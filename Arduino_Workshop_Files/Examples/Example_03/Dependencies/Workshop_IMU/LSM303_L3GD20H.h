/*
	LSM303_L3GD20H combo
*/

#include <Arduino.h>
#include <Wire.h>

#include <Math.h>
#include <Limits.h>

typedef struct
{
	/* Device ID and slave registers */
	byte who_am_i = 0x0F;
	byte device_id = 0xD4;
	byte slave_id = 0x6B;

	/* Data output registers */
	byte out_x_l = 0x28;
	byte out_x_h = 0x29;

	byte out_y_l = 0x2A;
	byte out_y_h = 0x2B;

	byte out_z_l = 0x2C;
	byte out_z_h = 0x2D;

	/* Control registers */
	byte ctrl_reg1 = 0x20;
	byte ctrl_reg2 = 0x21;
	byte ctrl_reg3 = 0x22;
	byte ctrl_reg4 = 0x23;
	byte ctrl_reg5 = 0x24;

	/* Ease of access: Gyro range selection */
	float range_250 = 0.00875f;
	float range_500 = 0.0175f;
	float range_2000 = 0.07f;
}l3gd20h;

typedef struct
{
	/* No device ID on LSM303; slave addr only*/
	byte slave_id = 0x19;

	/* Data output registers */
	byte out_x_l = 0x28;
	byte out_x_h = 0x29;

	byte out_y_l = 0x2A;
	byte out_y_h = 0x2B;

	byte out_z_l = 0x2C;
	byte out_z_h = 0x2D;

	/* Control Registers */
	byte ctrl_reg1 = 0x20;
	byte ctrl_reg2 = 0x21;
	byte ctrl_reg3 = 0x22;
	byte ctrl_reg4 = 0x23;
	byte ctrl_reg5 = 0x24;
	byte ctrl_reg6 = 0x25;
}lsm303_accl;

typedef struct
{
	/* No device ID on LSM303; slave addr only*/
	byte slave_id = 0x1E;

	/* Data output registers */
	byte out_x_h = 0x03;
	byte out_x_l = 0x04;

	byte out_z_h = 0x05;
	byte out_z_l = 0x06;

	byte out_y_h = 0x07;
	byte out_y_l = 0x08;

	/* Control Registers */
	byte crb_reg_m = 0x01;
	byte mr_reg_m = 0x02;

}lsm303_mag;

l3gd20h gyro;
lsm303_accl accl;
lsm303_mag mag;

float a[3] = { -1, -1, -1 };
float g[3] = { -1, -1, -1 };
float m[3] = { -1, -1, -1 };
float rpy[3] = { -1, -1, -1 };

void writeByte(byte slave_id, byte reg, byte value);
void readByte(byte slave_id, byte reg, byte *target);
void readAccl(float *a);
void readGyro(float *g);
void readMag(float *m);
void getRollPitchYaw();

void startSensor()
{
	Wire.begin();

	writeByte(accl.slave_id, accl.ctrl_reg1, 0b01010111);
	writeByte(accl.slave_id, accl.ctrl_reg4, 0b10001000);

	writeByte(mag.slave_id, mag.mr_reg_m, 0b00000000);
	writeByte(mag.slave_id, mag.crb_reg_m, 0b00100000);

	
	writeByte(gyro.slave_id, gyro.ctrl_reg1, 0b00001111);
	writeByte(gyro.slave_id, gyro.ctrl_reg4, 0b10000000);
}

void readAccl(float *a)
{
	Wire.beginTransmission(accl.slave_id);
	Wire.write(accl.out_x_l | 0x80);
	Wire.endTransmission();

	Wire.requestFrom(accl.slave_id, (byte)6);

	while (!Wire.available() >= 6)
		;

	uint8_t xl = Wire.read(), xh = Wire.read();
	uint8_t yl = Wire.read(), yh = Wire.read();
	uint8_t zl = Wire.read(), zh = Wire.read();

	int16_t x = ((xh << 8) | xl) >> 4;
	int16_t y = ((yh << 8) | yl) >> 4;
	int16_t z = ((zh << 8) | zl) >> 4;

	a[0] = (float)x / 1024;
	a[1] = (float)y / 1024;
	a[2] = (float)z / 1024;
}

void readGyro(float *g)
{
	Wire.beginTransmission(gyro.slave_id);
	Wire.write(gyro.out_x_l | 0x80);
	Wire.endTransmission();

	Wire.requestFrom(gyro.slave_id, (byte)6);

	while (!Wire.available() >= 6)
		;

	uint8_t xl = Wire.read(), xh = Wire.read();
	uint8_t yl = Wire.read(), yh = Wire.read();
	uint8_t zl = Wire.read(), zh = Wire.read();

	int16_t x = ((xh << 8) | xl);
	int16_t y = ((yh << 8) | yl);
	int16_t z = ((zh << 8) | zl);

	g[0] = (float)x * gyro.range_250;
	g[1] = (float)y * gyro.range_250;
	g[2] = (float)z * gyro.range_250;
}

void readMag(float *m)
{
	Wire.beginTransmission(mag.slave_id);
	Wire.write(mag.out_x_h);
	Wire.endTransmission();

	Wire.requestFrom(mag.slave_id, (byte)6);

	while (!Wire.available() >= 6)
		;

	uint8_t xh = Wire.read(), xl = Wire.read();
	uint8_t zh = Wire.read(), zl = Wire.read();
	uint8_t yh = Wire.read(), yl = Wire.read();

	int16_t x = (xh << 8) | xl;
	int16_t y = (yh << 8) | yl;
	int16_t z = (zh << 8) | zl;

	m[0] = (float)x / 1100 * 100;
	m[1] = (float)y / 1100 * 100;
	m[2] = (float)z / 980 * 100;
}

void writeByte(byte slave_id, byte reg, byte value)
{
	Wire.beginTransmission(slave_id);
	Wire.write(reg); Wire.write(value);
	if (slave_id == accl.slave_id)
		Wire.endTransmission(false);
	else
		Wire.endTransmission();
}

void readByte(byte slave_id, byte reg, byte *target)
{
	Wire.beginTransmission(slave_id);
	Wire.write(reg);
	if (slave_id == accl.slave_id)
		Wire.endTransmission(false);
	else
		Wire.endTransmission();

	Wire.requestFrom(slave_id, (byte)1);

	if (!Wire.available())
		*target = -1;
	else *target = Wire.read();
}

void getRollPitchYaw()
{
	rpy[0] = (float)atan2(a[1], a[2]);
	if (a[1] * sin(rpy[0]) + a[2] * cos(rpy[0]) == 0)
		rpy[1] = a[0] > 0 ? (PI / 2) : (-PI / 2);
	rpy[1] = (float)atan(-a[0] / ((a[1] * sin(rpy[0])) + (a[2] * cos(rpy[0]))));
	rpy[2] = (float)atan2((m[2] * sin(rpy[0])) - (m[1] * cos(rpy[0])), (m[0] * cos(rpy[1])) + (m[1] * sin(rpy[1]) * sin(rpy[0])) + (m[2] * sin(rpy[1]) * cos(rpy[0])));

	rpy[0] *= 180 / PI;
	rpy[1] *= 180 / PI;
	rpy[2] *= 180 / PI;
}

void readSensor()
{
	readAccl(a);
	readGyro(g);
	readMag(m);

	getRollPitchYaw();
}