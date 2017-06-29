// This is the header file. Header file defines all necessary variables and functions.

#include "Arduino.h"
#include <Wire.h>

#define ADDRESS 0x1D
#define REG_OUT_X_MSB 0x01
#define REG_SYSMOD 0x0B
#define REG_WHOAMI 0x0D
#define REG_XYZ_DATA_CFG 0x0E

#define REG_CTRL_REG1 0x2A
#define REG_CTRL_REG2 0x2B
#define REG_CTRL_REG4 0x2D
#define REG_CTRL_REG5 0x2E

#define RANGE_8_G 0b10
#define RANGE_4_G 0b01
#define RANGE_2_G 0b00

#define RATE_800_HZ 0b000

// This will define class object
class Works_Accel
{
public: // Anything under public is visible to Arduino IDE as well
	bool begin();
	void read();

	typedef struct
	{
		uint16_t x, y, z;
		float xg, yg, zg;
	} vector_acc;

	vector_acc vector;

private: // Anything under private is not visible to Arduino IDE
	uint8_t i2cRead();
	void i2cWrite(uint8_t x);
	void writeRegister(uint8_t reg, uint8_t val);
	uint8_t readRegister(uint8_t reg);
};
// End of header file
