// This is the actual file where all the functions are executed.

#include "Arduino.h"
#include <Wire.h>

#include <Works_Accel.h> // Since we are using header file

bool Works_Accel::begin()
{
	Wire.begin();

	writeRegister(REG_CTRL_REG2, 0x04); // Reset sensor
	while (readRegister(REG_CTRL_REG2) & 0x04); // Wait until sensor resets

	writeRegister(REG_XYZ_DATA_CFG, RANGE_2_G);
	writeRegister(REG_CTRL_REG2, 0x02); // High resolution
	writeRegister(REG_CTRL_REG4, 0x01); // Low noise
	writeRegister(REG_CTRL_REG4, 0x01); // DRDY to INT1
	writeRegister(REG_CTRL_REG5, 0x01);

	writeRegister(REG_CTRL_REG1, 0x01); // Start sensor

	return true;
}

void Works_Accel::read()
{
	Wire.beginTransmission(ADDRESS);
	i2cWrite(REG_OUT_X_MSB);
	Wire.endTransmission(false);

	Wire.requestFrom(ADDRESS, 6);
	vector.x = Wire.read(); vector.x <<= 8; vector.x |= Wire.read(); vector.x >>= 2;
	vector.y = Wire.read(); vector.y <<= 8; vector.y |= Wire.read(); vector.y >>= 2;
	vector.z = Wire.read(); vector.z <<= 8; vector.z |= Wire.read(); vector.z >>= 2;

	vector.xg = (float)vector.x / 4096;
	vector.yg = (float)vector.y / 4096;
	vector.zg = (float)vector.z / 4096;
}

uint8_t Works_Accel::i2cRead()
{
	return Wire.read();
}

void Works_Accel::i2cWrite(uint8_t x)
{
	Wire.write(x);
}

void Works_Accel::writeRegister(uint8_t reg, uint8_t val)
{
	Wire.beginTransmission(ADDRESS);
	i2cWrite(reg);
	i2cWrite(val);
	Wire.endTransmission();
}

uint8_t Works_Accel::readRegister(uint8_t reg)
{
	Wire.beginTransmission(ADDRESS);
	i2cWrite(reg);
	Wire.endTransmission(false);

	Wire.requestFrom(ADDRESS, 1);
	if (!Wire.available()) return -1;

	return i2cRead();
}
