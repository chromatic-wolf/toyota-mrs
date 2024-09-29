#include <Arduino.h>
#include <SPI.h> //Library for using SPI Communication
#include <mcp2515.h>
#include "common/CapMoistureSensor.h"
#include "CanData.h"

class CanBusController
{
private:
    CanData *_canData;
    MCP2515 *_mcp2515; // change this to the CS pin of whatever board you have
    u_int *_can_controller_id;

public:
    CanBusController(u_int can_id, u_int CS_PIN, CAN_SPEED can_speed = CAN_1000KBPS, CAN_CLOCK can_clock = MCP_8MHZ);

    ~CanBusController();
    MCP2515::ERROR sendMessage(unsigned char canID, unsigned char frameSize = 8, unsigned char data[8]);
    CanData readMessage();
};

