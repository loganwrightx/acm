/*
Author: Logan Wright

Server for handling Gravitas protocol comms.
*/

#ifndef GRAVITAS_SERVER_H
#define GRAVITAS_SERVER_H

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "gravitas.h"

#define PORT 1198
#define ADDRESS "20.25.1.1"

class GravitasServer {
public:
    GravitasServer();
    ~GravitasServer();

private:
    int sSockFd;
    struct sockaddr_in sAddr;
    std::vector<uint8_t> sBuffer;

    void init();
};

#endif