#include <Wire.h>

void accelerometerInit(void){
  WireWriteRegister(SensorAccelerometer, 0x31, 1);
  WireWriteRegister(SensorAccelerometer, 0x2D, 1 << 3);
}

void getAccel(void){
  size_t const DataLength = 6;
  uint32_t data[DataLength] = {0};
  WireWriteByte(SensorAccelerometer, 0x32);
  WireRequestArray(SensorAccelerometer, data, DataLength);
  uint16_t xi = (data[1] << 8) | data[0];
  uint16_t yi = (data[3] << 8) | data[2];
  uint16_t zi = (data[5] << 8) | data[4];
  accel.x = (double)(*(int16_t*)(&xi) / SensorMaximumReading * SensorMaximumAccel);
  accel.y = (double)(*(int16_t*)(&yi) / SensorMaximumReading * SensorMaximumAccel);
  accel.z = (double)(*(int16_t*)(&zi) / SensorMaximumReading * SensorMaximumAccel);
  double norm = sqrt((accel.z * accel.z + accel.x * accel.x + accel.y * accel.y));
  accel.x /= (norm == 0) ? 1 : norm;
  accel.y /= (norm == 0) ? 1 : norm;
  accel.z /= (norm == 0) ? 1 : norm;
}
