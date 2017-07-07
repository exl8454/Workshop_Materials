/*
	Workshop_IMU.h
	Example_03
*/

#include <Wire.h>
#include <Arduino.h>
#include <Math.h>

typedef struct
{
	/* Device ID and slave registers */
	byte who_am_i = 0x0D;
	byte device_id = 0x1A;
	byte slave_id = 0x1C;

	/* Data output registers */
	byte out_x_h = 0x01;
	byte out_x_l = 0x02;

	byte out_y_h = 0x03;
	byte out_y_l = 0x04;

	byte out_z_h = 0x05;
	byte out_z_l = 0x06;

	/* Control registers */
	byte ctrl_reg1 = 0x2A;
	byte ctrl_reg2 = 0x2B;
	byte ctrl_reg3 = 0x2C;
	byte ctrl_reg4 = 0x2D;
	byte ctrl_reg5 = 0x2E;
	byte ctrl_rang = 0x0E;

	/* Ease of access: Accelerometer range selection */
	uint16_t range_2g = 4096;
	uint16_t range_4g = 2048;
	uint16_t range_8g = 1024;
}mma8451;

typedef struct
{
	/* Device ID and slave registers */
	byte who_am_i = 0x0F;
	byte device_id = 0xD3;
	byte slave_id = 0x69;

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
}l3gd42k;

byte sensor_status = 0b00;

mma8451 accl;
uint16_t accl_range = 1;

l3gd42k gyro;
float gyro_range = 1;

float a[3] = { -1, -1, -1 };
float g[3] = { -1, -1, -1 };
float rpy[3] = { -1, -1, -1 };

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

void readAccl(float* a)
{
	Wire.beginTransmission(accl.slave_id);
	Wire.write(accl.out_x_h);
	Wire.endTransmission(false);

	Wire.requestFrom(accl.slave_id, (byte)6);

	while (!Wire.available() >= 6)
		;

	byte xh = Wire.read(), xl = Wire.read();
	byte yh = Wire.read(), yl = Wire.read();
	byte zh = Wire.read(), zl = Wire.read();

	int16_t x = (int16_t) (((xh << 8) | xl) >> 2);
	int16_t y = (int16_t) (((yh << 8) | yl) >> 2);
	int16_t z = (int16_t) (((zh << 8) | zl) >> 2);

	a[0] = (float)x / accl_range;
	a[1] = (float)y / accl_range;
	a[2] = (float)z / accl_range;
}

void readGyro(float* g)
{
	Wire.beginTransmission(gyro.slave_id);
	Wire.write(gyro.out_x_l | 0x80);
	Wire.endTransmission();

	Wire.requestFrom(gyro.slave_id, (byte)6);
	while (!Wire.available() >= 6)
		;

	byte xl = Wire.read(), xh = Wire.read();
	byte yl = Wire.read(), yh = Wire.read();
	byte zl = Wire.read(), zh = Wire.read();

	int16_t x = (xh << 8) | xl;
	int16_t y = (yh << 8) | yl;
	int16_t z = (zh << 8) | zl;

	g[0] = (float)x * gyro_range;
	g[1] = (float)y * gyro_range;
	g[2] = (float)z * gyro_range;
}

void startSensor()
{
	accl_range = accl.range_2g;
	
	Wire.begin();
	byte testByte = -1;
	
	readByte(gyro.slave_id, gyro.who_am_i, &testByte);
	if (testByte != gyro.device_id)
		sensor_status |= 0b00;
	else
	{
		sensor_status |= 0b10;

		gyro_range = gyro.range_250;
		writeByte(gyro.slave_id, gyro.ctrl_reg1, 0x0F);
		writeByte(gyro.slave_id, gyro.ctrl_reg2, 0x20);
		writeByte(gyro.slave_id, gyro.ctrl_reg4, 0x80);
	}

	readByte(accl.slave_id, accl.who_am_i, &testByte);
	if (testByte != accl.device_id)
		sensor_status |= 0b00;
	else
	{
		sensor_status |= 0b01;

		writeByte(accl.slave_id, accl.ctrl_reg2, 0x40); /* Reset */
		readByte(accl.slave_id, accl.ctrl_reg2, &testByte);
		while (testByte & 0x40)
			readByte(accl.slave_id, accl.ctrl_reg2, &testByte);

		accl_range = accl.range_2g;
		writeByte(accl.slave_id, accl.ctrl_rang, accl.range_2g);
		writeByte(accl.slave_id, accl.ctrl_reg2, 0x02);
		writeByte(accl.slave_id, accl.ctrl_reg1, 0x05);
	}
}

void readSensors()
{
	readAccl(a);
	readGyro(g);
}

/*
For L3G4200D + MMA8452 
X on accl goes with Y on gyro
Y on accl goes with -X on gyro
Z is same
*/

void getRoll()
{
	rpy[0] = (float)atan2(a[1] / a[2]);
	rpy[1] = (float)atan(-a[0] / (y * sin(rpy[0] + z * cos(rpy[0]));
}