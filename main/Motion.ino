#include <Wire.h>
uint16_t xi;
uint16_t yi;
uint16_t zi;

void WireRequestArray(int address, uint8_t* buffer, uint8_t amount);
void WireWriteRegister(int address, uint8_t reg, uint8_t value);
void WireWriteByte(int address, uint8_t value);


static float const    SensorMaximumReading= 512.0;
static float const    SensorMaximumAccel  = 9.81 * 4.0;
static uint8_t const  SensorAccelerometer = 0x1D;
//static uint32_t const ShakeThreshold      = 16;
static float          ShakeAccumulator    = 0;


void accelerometerInit(void)
{
  WireWriteRegister(SensorAccelerometer, 0x31, 1); //sets to Range to 4g
  WireWriteRegister(SensorAccelerometer, 0x2D, 1 << 3);  // activates measurement
}


void getAccel(void)
{
  size_t const DataLength = 6;
  uint32_t data[DataLength] = {0};
  WireWriteByte(SensorAccelerometer, 0x32);
  WireRequestArray(SensorAccelerometer, data, DataLength);
  uint16_t xi = (data[1] << 8) | data[0];
  uint16_t yi = (data[3] << 8) | data[2];
  uint16_t zi = (data[5] << 8) | data[4];
  accel.x = (double)(*(int16_t*)(&xi) / SensorMaximumReading * SensorMaximumAccel);
  accel.y = (double)(*(int16_t*)(&yi) / SensorMaximumReading * SensorMaximumAccel);
  double z = (double)(*(int16_t*)(&yi) / SensorMaximumReading * SensorMaximumAccel);
  double norm = sqrt((z * z + accel.x * accel.x + accel.y * accel.y));
  accel.x /= norm;
  accel.y /= norm;
}
