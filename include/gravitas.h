/*
Author: Logan Wright

Gravitas protocol header
*/

#ifndef GRAVITAS_H
#define GRAVITAS_H

#include <vector>
#include <iostream>
#include <chrono>

#include "gravitas_message_types.h"
#include "gravitas_message.h"

class Gravitas {
public:
    Gravitas(std::vector<uint8_t> buffer);
    Gravitas(gravitas_message_t type, std::vector<uint8_t> buffer);
    Gravitas(gravitas_message_t type, GravitasMessage& message);
    ~Gravitas();

    virtual void pack(std::vector<uint8_t>& buffer) { std::cout << "Gravitas::pack() not implemented" << std::endl; }
    virtual void unpack(std::vector<uint8_t>& buffer) { std::cout << "Gravitas::unpack() not implemented" << std::endl; }

    uint16_t id() { return mId; }
    uint32_t timeStamp() { return mTimeStamp; }
    gravitas_message_t type() { return mType; }

    uint32_t crc32();
    bool validateBuffer(std::vector<uint8_t> buffer, uint8_t padding);

    template <typename T> void encodeValue(std::vector<uint8_t>& buffer, T value);
    template <typename T> void decodeValue(std::vector<uint8_t>& buffer, T& value);

private:
    uint16_t mId;
    uint32_t mTimeStamp;
    gravitas_message_t mType;
    uint32_t mCrc;

    GravitasMessage* mMessage;
};

#endif