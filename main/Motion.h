#ifndef MOTION_H
#define MOTION_H
void getAccel(void);
void accelerometerInit(void);
void MoveBall(void);
void WireInit(void);
uint16_t xi;
uint16_t yi;
uint16_t zi;

void WireRequestArray(int address, uint8_t* buffer, uint8_t amount);
void WireWriteRegister(int address, uint8_t reg, uint8_t value);
void WireWriteByte(int address, uint8_t value);


static float const    SensorMaximumReading= 512.0;
static float const    SensorMaximumAccel  = 9.81 * 4.0;
static uint8_t const  SensorAccelerometer = 0x1D;
#endif
