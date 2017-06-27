/*
	LIS3DH Sensor I2C Library for Arduino

	Writtne by Charlie Shin
	Last Edited 2017 June 27th
*/
#ifndef LIS3DH
#define LIS3DH

#include <Arduino.h> /* AVR Dependency for Arduino */
#include <Wire.h> /* I2C Library */

/* Typedef is like dictionary in Python. It can handle multiple data in single variable */
typedef struct
{
	/* Device ID resisters */
	byte who_am_i = 0x0F;
	byte device_id = 0x33;
	byte slave_addr = 0x18; /* Change to 0x19 if SDO is connected to 3.3V*/

	/* Sensor control resisters */
	byte ctrl_reg1 = 0x20;
	byte ctrl_reg2 = 0x21;
	byte ctrl_reg3 = 0x22;
	byte ctrl_reg4 = 0x23;
	byte ctrl_reg5 = 0x24;
	byte ctrl_reg6 = 0x25;

	/* Output control resisters */
	byte out_x_l = 0x28;
	byte out_x_h = 0x29;
	byte out_y_l = 0x2A;
	byte out_y_h = 0x2B;
	byte out_z_l = 0x2C;
	byte out_z_h = 0x2D;
}lis3dh;

lis3dh sensor; /* Declare struct typedef as variable to use later */

void writeByte(byte reg, byte value)
{
	Wire.beginTransmission(sensor.slave_addr);
	Wire.write(reg); Wire.write(value);
	Wire.endTransmission();
}

byte readByte(byte reg)
{
	Wire.beginTransmission(sensor.slave_addr);
	Wire.write(reg);
	Wire.endTransmission();

	Wire.requestFrom(sensor.slave_addr, (byte) 1);

	byte data = Wire.read();

	return data;
} /* There are more ways to read data but this is the easiest to understand */

void startSensor()
{
	/* Start the I2C comm */
	Wire.begin();
	/* First we need to check if we have sensor connected by reading the Who Am I Register*/
	byte device = readByte(sensor.who_am_i);
	if (device != sensor.device_id);

	/* If sensor is connected, start changing configuration */
	writeByte(sensor.ctrl_reg1, 0x77);
	writeByte(sensor.ctrl_reg3, 0x10);
	writeByte(sensor.ctrl_reg4, 0x98);

	/* Sensor is ready to go! */
}

void readSensor(float *gx, float *gy, float *gz)
{
	/*
		Datasheet says outputs are 16-bit (hence why we have 2 registers for one axis) 
		There are multiple ways to read values, but we will be using simple way.
		First we read data from each registers
	*/
	uint8_t xl = readByte(sensor.out_x_l);
	uint8_t xh = readByte(sensor.out_x_h);
	uint8_t yl = readByte(sensor.out_y_l);
	uint8_t yh = readByte(sensor.out_y_h);
	uint8_t zl = readByte(sensor.out_z_l);
	uint8_t zh = readByte(sensor.out_z_h);

	/* Now to convert this, we shift high bits to LEFT so low bits stays on RIGHT */
	int16_t x = (int16_t)(xl | (xh << 8));
	int16_t y = (int16_t)(yl | (yh << 8));
	int16_t z = (int16_t)(zl | (zh << 8));

	/* If you try to print this value, this will give you raw output. We need to convert this */
	*gx = (float)x / 8190;
	*gy = (float)y / 8190;
	*gz = (float)z / 8190;
}
#endif
