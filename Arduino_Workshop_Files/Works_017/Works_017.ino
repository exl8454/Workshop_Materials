// Arduino Workshop
// Works_017
// I2C Communication (1)

/**
 * I2C stands for Inter-Integrated Circuit.
 * 
 * I2C consist of two main parts; master and slave.
 * Master is a device which requests data from slave.
 * Slave is a device which receives and sends data from master.
 * 
 * As for example, we will be using MMA8451 acceleration sensor.
 */

#include <Wire.h> // #include is C keyword to add 'package' to a file.

#define ADDRESS 0x1D // #define keyword simply replaces  defined keyword.
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

// Variables
static int16_t x, y, z;
static float g_x, g_y, g_z;

void setup()
{
  Wire.begin();
  
  writeRegister(REG_CTRL_REG2, 0x04); // Reset sensor
  while(readRegister(REG_CTRL_REG2) & 0x04); // Wait until sensor resets

  writeRegister(REG_XYZ_DATA_CFG, RANGE_2_G);
  writeRegister(REG_CTRL_REG2, 0x02); // High resolution
  writeRegister(REG_CTRL_REG4, 0x01); // Low noise
  writeRegister(REG_CTRL_REG4, 0x01); // DRDY to INT1
  writeRegister(REG_CTRL_REG5, 0x01);

  writeRegister(REG_CTRL_REG1, 0x01); // Start sensor
   
  Serial.begin(9600);
}

void loop()
{
  read();
  Serial.print("X: "); Serial.print(g_x);
  Serial.print(" Y: "); Serial.print(g_y);
  Serial.print(" Z: "); Serial.println(g_z);
  Serial.println();
  delay(100);
}

uint8_t i2cRead()
{
  return Wire.read();
}

void i2cWrite(uint8_t x)
{
  Wire.write((uint8_t) x);
}

void writeRegister(uint8_t reg, uint8_t val)
{
  Wire.beginTransmission(ADDRESS);
  i2cWrite(reg);
  i2cWrite(val);
  Wire.endTransmission();
}

uint8_t readRegister(uint8_t reg)
{
  Wire.beginTransmission(ADDRESS);
  i2cWrite(reg);
  Wire.endTransmission(false); // Sending the parameter false will keep the line alive.

  Wire.requestFrom(ADDRESS, 1);
  if(!Wire.available()) return -1;
  return i2cRead();
}

void read()
{
  Wire.beginTransmission(ADDRESS);
  i2cWrite(REG_OUT_X_MSB);
  Wire.endTransmission(false);

  Wire.requestFrom(ADDRESS, 6);
  x = Wire.read(); x <<= 8; x |= Wire.read(); x >>= 2;
  y = Wire.read(); y <<= 8; y |= Wire.read(); y >>= 2;
  z = Wire.read(); z <<= 8; z |= Wire.read(); z >>= 2;

  // For 8G, divide by 1024
  // For 4G, divide by 2048
  // For 2G, divide by 4096
  g_x = (float) x / 4096;
  g_y = (float) y / 4096;
  g_z = (float) z / 4096;
}

