/*
Author: Logan Wright

Gravitas protocol implementation
*/

#include "gravitas.h"

Gravitas::Gravitas(gravitas_message_t type): mType(type) {
    // TODO: Implement creation logic here
}

Gravitas::~Gravitas() {
    std::cout << "Message has type: " << static_cast<int>(mType) << std::endl;
}