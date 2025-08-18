/*
Author: Logan Wright

Description: App to run on flight hardware (RPi 5 8Gb ram) for rockets.
*/

#include <iostream>

#include "gravitas.h"

int main(int argc, char** argv) {
    std::cout << "Avionics Core Module" << std::endl;

    std::vector<uint8_t> buffer;

    std::cout << "Gravitas packet size: " << sizeof(Gravitas) << std::endl;

    Gravitas* msg = new Gravitas(gravitas_message_t::TELEMETRY, buffer);
    msg->pack(buffer);
    msg->unpack(buffer);

    std::cout << "Message type: " << static_cast<int>(msg->type()) << std::endl;

    delete msg;
    return 0;
}