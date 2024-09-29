#include "CanBusController.h"

CanBusController::CanBusController(u_int can_id, u_int CS_PIN, CAN_SPEED can_speed, CAN_CLOCK can_clock)
{
    Serial.println((String) "Setting up controller");
    SPI.begin();
    _canMsg = new can_frame();
    Serial.println((String) "Can frame object created");
    Serial.println((String) "SPI started");
    _mcp2515 = new MCP2515(CS_PIN); // need to give the CS pin of the SPI interface so the can controller knows where to communicate default setup on the arduino wifi controller is 15
    Serial.println((String) "MCP2515 initianted");
    _mcp2515->reset();
    Serial.println((String) "mcp2515 rest");
    _mcp2515->setBitrate(can_speed, can_clock); // Sets CAN at speed anything 1000KBps or less and Clock 8MHz
    Serial.println((String) "mcp2515 bitrate set to: " + can_speed);
    Serial.println((String) "mcp2515 can clock set to: " + can_clock);
    _mcp2515->setNormalMode();

    _can_controller_id = new uint(can_id);

    Serial.println("Setup complete");
}

CanBusController::~CanBusController()
{
    delete _canMsg;
    delete _mcp2515; // change this to the CS pin of whatever board you have
    delete _can_controller_id;
}

MCP2515::ERROR CanBusController::sendMessage(unsigned char canID, unsigned char frameSize, unsigned char data[8])
{
    _canMsg->can_id = canID;      // CAN id as 0x036
    _canMsg->can_dlc = frameSize; // CAN data length as 8
    _canMsg->data[0] = data[0];   // first byte is the button state
    _canMsg->data[1] = data[1];
    _canMsg->data[2] = data[2];
    _canMsg->data[3] = data[3];
    _canMsg->data[4] = data[4];
    _canMsg->data[5] = data[5];
    _canMsg->data[6] = data[6];
    _canMsg->data[7] = data[7];
    Serial.println("Sending message: ");

    return _mcp2515->sendMessage(_canMsg);
}
