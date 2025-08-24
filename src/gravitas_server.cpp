/*
Author: Logan Wright
*/


#include "gravitas_server.h"


GravitasServer::GravitasServer() {
    std::cout << "GravitasServer()" << std::endl;
}


GravitasServer::~GravitasServer() {
    std::cout << "GravitasServer()" << std::endl;
}


void GravitasServer::init() {
    if ((sSockFd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Could not create gravitas server socket");
        exit(EXIT_FAILURE);
    }

    memset(&sAddr, 0, sizeof(sAddr));

    sAddr.sin_family = AF_INET;
    sAddr.sin_port = htons(PORT);
    sAddr.sin_addr.s_addr = inet_addr(ADDRESS);

    if (bind(sSockFd, (const sockaddr*)&sAddr, sizeof(sAddr)) == -1) {
        perror("Failed to bind server to socket");
        exit(EXIT_FAILURE);
    }
}