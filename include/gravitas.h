/*
Author: Logan Wright

Gravitas protocol header
*/

#ifndef GRAVITAS_H
#define GRAVITAS_H

#include <vector>
#include <stdint.h>
#include <iostream>

#include "gravitas_message_types.h"

class Gravitas {
public:
    Gravitas(gravitas_message_t type);
    ~Gravitas();

    virtual void pack(std::vector<uint8_t>& buffer) { std::cout << "Gravitas::pack() not implemented" << std::endl; }
    virtual void unpack(std::vector<uint8_t>& buffer) { std::cout << "Gravitas::unpack() not implemented" << std::endl; }

private:
    uint8_t mId;
    gravitas_message_t mType;
    std::vector<uint8_t> mPayload;
};

#endif