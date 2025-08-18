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

#define PORT 9876

class GravitasServer {
public:
    GravitasServer();
    ~GravitasServer();

    void init();

private:
    int sSockFd;
    struct sockaddr_in sAddr;
    std::vector<uint8_t> sBuffer;
};

#endif