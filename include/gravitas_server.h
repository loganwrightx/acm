/*
Author: Logan Wright

Server for handling Gravitas protocol comms.
*/

#ifndef GRAVITAS_SERVER_H
#define GRAVITAS_SERVER_H

#include <iostream>

#include "gravitas.h"

class GravitasServer {
public:
    GravitasServer();
    ~GravitasServer();

private:
    uint8_t sId;
};

#endif