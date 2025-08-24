/*
Author: Logan Wright

Gravitas protocol implementation

Packet structure:

=== Header ===
mId
mTimeStamp
mType

=== Payload ===
mMessage

=== CRC32 ===
mCrc

Messages are modelled after the template class GravitasMessage. This is how
payloads are organized to handle all communication means in the protocol.
*/


#include "gravitas.h"


/// @brief Create a Gravitas protocol packet from a raw buffer
/// @param buffer Raw buffer from network in network byte order
Gravitas::Gravitas(std::vector<uint8_t> buffer) : mId(0), mTimeStamp(std::chrono::system_clock::now().time_since_epoch().count()) {
    std::cout << "Gravitas()" << std::endl;
    if (!validateBuffer(buffer, sizeof(mId) + sizeof(mTimeStamp)));
    
    mType = static_cast<gravitas_message_t>(buffer[0]);
    buffer.erase(buffer.begin());

    mMessage = new GravitasMessage();
    mMessage->unpack(buffer);

    mCrc = crc32();
}


/// @brief Create a Gravitas protocol packet with a payload created from a raw packet
/// @param type Gravitas protocol payload type
/// @param buffer Raw buffer in network byte order
Gravitas::Gravitas(gravitas_message_t type, std::vector<uint8_t> buffer) : mId(0), mTimeStamp(std::chrono::system_clock::now().time_since_epoch().count()), mType(type) {
    std::cout << "Gravitas()" << std::endl;
    validateBuffer(buffer, sizeof(mId) + sizeof(mTimeStamp) + sizeof(mType));

    mMessage = new GravitasMessage();
    mMessage->unpack(buffer);

    mCrc = crc32();
}


/// @brief Create a Gravitas protocol packet with the message payload given
/// @param type Gravitas protocol payload type
/// @param message Completed Gravitas payload object
Gravitas::Gravitas(gravitas_message_t type, GravitasMessage& message) : mId(0), mTimeStamp(std::chrono::system_clock::now().time_since_epoch().count()), mType(type), mMessage(&message) {
    std::cout << "Gravitas()" << std::endl;
    mCrc = crc32();
}


Gravitas::~Gravitas() {
    std::cout << "Message has type: " << static_cast<int>(mType) << std::endl;
}


/// @brief Computes crc32 for the Gravitas object data
/// @return The crc32 in integer form
uint32_t Gravitas::crc32() {
    // TODO: Implement crc32 algorithm
    return 0xFF000000;
}


/// @brief Verify buffer for loading bytes into Gravitas protocol packet
/// @param buffer Raw network byte order buffer
/// @param padding Size of buffer that can be excluded from size confirmation
/// @return Whether the buffer is validated or not
bool Gravitas::validateBuffer(std::vector<uint8_t> buffer, uint8_t padding) {
    // TODO: Implement logic for size validation
    if (buffer.size() < sizeof(Gravitas) - padding && 0) {
        std::cout << "Gravitas message creation failed - incorrect buffer size!" << std::endl;
        return false;
    }

    // TODO: Implement logic for crc32 validation

    return true;
}


/// @brief Encode a single variable into buffer
/// @tparam T generic non-custom datatype i.e. int, long, float, double, etc.
/// @param buffer 
/// @param value 
template <typename T> void Gravitas::encodeValue(std::vector<uint8_t>& buffer, T value) {
    for (size_t idx = 0; idx < sizeof(T); idx++) {
        buffer.push_back((uint8_t)(value >> (idx * 8) & 0xFF));
    }
}


/// @brief Decode a single variable from the buffer
/// @tparam T generic non-custom datatype i.e. int, long, float, double, etc.
/// @param buffer 
/// @param value 
template <typename T> void Gravitas::decodeValue(std::vector<uint8_t>& buffer, T& value) {
    size_t size = sizeof(T);
    T tmp;
    for (size_t idx = 0; idx < sizeof(T); idx++) {
        tmp += buffer[idx];
    }
}