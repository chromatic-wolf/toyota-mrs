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
