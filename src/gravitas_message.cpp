/*
Author: Logan Wright

Base template for all message structures in the Gravitas protocol layer.
*/

#include "gravitas_message.h"


/// @brief Base payload template constructor
GravitasMessage::GravitasMessage() {
    std::cout << "GravitasMessage() not implemented" << std::endl;
}


/// @brief Base payload template destructor
GravitasMessage::~GravitasMessage() {
    std::cout << "~GravitasMessage()" << std::endl;
}


/// @brief Packs Gravitas payload object into buffer
/// @param buffer
void GravitasMessage::pack(std::vector<uint8_t>& buffer) {
    // TODO: Implement pack logic
    std::cout << "GravitasMessage::pack not implemented" << std::endl;
}


/// @brief Unpacks buffer into Gravitas payload object
/// @param buffer 
void GravitasMessage::unpack(std::vector<uint8_t>& buffer) {
    // TODO: Implement unpack logic
    std::cout << "GravitasMessage::unpack not implemented" << std::endl;
}