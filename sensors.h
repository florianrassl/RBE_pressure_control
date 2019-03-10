#ifndef SENSORS_H
#define SENSORS_H

#include <stdint.h>

class Sensors
{
public:
    Sensors();
    const uint8_t sAnz = 7;
    float *sData = new float[sAnz];
};

#endif // SENSORS_H
