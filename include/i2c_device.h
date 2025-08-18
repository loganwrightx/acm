/*
Author: Logan Wright
*/

#ifndef I2C_DEVICE_H
#define I2C_DEVICE

#include <vector>

class I2cDevice {
public:
    I2cDevice() {}
    ~I2cDevice() {}

    virtual void init() {}
    virtual void readData() {}

private:
    uint8_t iAddr;
};

#endif