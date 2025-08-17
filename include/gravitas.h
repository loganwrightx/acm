/*
Author: Logan Wright

Gravitas protocol header
*/

#ifndef GRAVITAS_H
#define GRAVITAS_H

#include <vector>
#include <stdint.h>

class Gravitas {
public:
    Gravitas();
    ~Gravitas();

    virtual void pack(std::vector<uint8_t>& buffer) {}
    virtual Gravitas unpack(std::vector<uint8_t>& buffer) {}

private:
    std::vector<uint8_t> _data;
};

#endif