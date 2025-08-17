/*
Author: Logan Wright

Message types are separated into a few categories:
- Commands
    - System command (firmware interactions)
    - Mission command (mission planning)
    - Vehicle command (hardware interactions)
- Reports
    - System report
    - Mission report
    - Vehicle report
- Telemetry (system, mission, and vehicle readouts)
*/

#ifndef GRAVITAS_MESSAGE_TYPES_H
#define GRAVITAS_MESSAGE_TYPES_H

#include <stdint.h>

typedef enum class GravitasMessage_t: uint8_t {
    SYSTEM_COMMAND = 0,
    MISSION_COMMAND,
    VEHICLE_COMMAND,

    SYSTEM_REPORT,
    MISSION_REPORT,
    VEHICLE_REPORT,

    TELEMETRY
} gravitas_message_t;

#endif