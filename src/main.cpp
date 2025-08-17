/*
Author: Logan Wright

Description: App to run on flight hardware (RPi 5 8Gb ram) for rockets.
*/

#include <iostream>

#include "gravitas.h"

int main(int argc, char** argv) {
    std::cout << "Avionics Core Module" << std::endl;
    Gravitas* msg = new Gravitas(gravitas_message_t::TELEMETRY);
    std::vector<uint8_t> buffer;
    msg->pack(buffer);
    msg->unpack(buffer);
    delete msg;
    return 0;
}