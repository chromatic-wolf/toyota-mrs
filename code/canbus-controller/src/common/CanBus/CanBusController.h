#include <Arduino.h>
#include <SPI.h> //Library for using SPI Communication
#include <mcp2515.h>
#include "common/CapMoistureSensor.h"

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
    MCP2515::ERROR readMessage();
};

class CanData
{
private:
    struct can_frame *_canFrame;

public:
    CanData();
    ~CanData();
    MCP2515::ERROR errorStatus;
    can_frame getData();
    void setData(can_frame canFrame);

    MCP2515::ERROR getErrorStatus;
    void setErrorStatus(MCP2515::ERROR errorStatus);
};