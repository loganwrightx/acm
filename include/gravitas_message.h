/*
Author: Logan Wright

Base template for all message structures in the Gravitas protocol layer.
*/

#ifndef GRAVITAS_PAYLOAD_H
#define GRAVITAS_PAYLOAD_H

#include <vector>
#include <iostream>

class GravitasMessage {
public:
    GravitasMessage();
    ~GravitasMessage();

    virtual void pack(std::vector<uint8_t>& buffer);
    virtual void unpack(std::vector<uint8_t>& buffer);

private:
    // Nothing needed yet for base class
};

#endif