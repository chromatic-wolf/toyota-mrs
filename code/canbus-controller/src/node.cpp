#include "node.h"

Node::Node(int relay_pin, u_int can_id, int CS_PIN, CAN_SPEED can_speed, CAN_CLOCK can_clock)
{
    Serial.println((String) "Setting up node");
    SPI.begin();
    Serial.println((String) "SPI started");
    _canMsg = new can_frame();
    Serial.println((String) "Can frame object created");
    _mcp2515 = new MCP2515(CS_PIN); // need to give the CS pin of the SPI interface so the can controller knows where to communicate
    Serial.println((String) "MCP2515 initianted");
    _mcp2515->reset();
    Serial.println((String) "mcp2515 rest");
    _mcp2515->setBitrate(can_speed, can_clock); // Sets CAN at speed 500KBPS and Clock 8MHz
    Serial.println((String) "mcp2515 bitrate set to: " + can_speed);
    Serial.println((String) "mcp2515 can clock set to: " + can_clock);
    _mcp2515->setNormalMode();
    _relay_pin = new int(relay_pin);
    pinMode(*_relay_pin, OUTPUT);
    digitalWrite(*_relay_pin, HIGH);
    _can_controller_id = new uint(can_id);
    _canError = new MCP2515::ERROR();

    Serial.println("Setup complete");
}

Node::~Node()
{
    delete _canMsg;
    delete _mcp2515;
    delete _relay_pin;
    delete _canError;
}

void Node::loop()
{

    *_canError = _mcp2515->readMessage(_canMsg);
    if (*_canError == MCP2515::ERROR_OK)
    {
        Serial.println((String) "Data received");
        Serial.println((String) "From ID: " + _canMsg->can_id);
        Serial.println((String) "Length: " + _canMsg->can_dlc);
        Serial.println((String) "Bit 1: " + _canMsg->data[0]);
        Serial.println((String) "Bit 2: " + _canMsg->data[1]);
        Serial.println((String) "Bit 3: " + _canMsg->data[2]);
        Serial.println((String) "Bit 4: " + _canMsg->data[3]);
        Serial.println((String) "Bit 5: " + _canMsg->data[4]);
        Serial.println((String) "Bit 6: " + _canMsg->data[5]);
        Serial.println((String) "Bit 7: " + _canMsg->data[6]);
        Serial.println((String) "Bit 8: " + _canMsg->data[7]);

        if (_canMsg->can_id == 1 && _canMsg->data[0] == 1)
        {
            // turn light on
            digitalWrite(*_relay_pin, LOW);
        }
        else if (_canMsg->can_id == 1 && _canMsg->data[0] == 0)
        {
            // turn light off
            digitalWrite(*_relay_pin, HIGH);
        }
    }
    else if (*_canError < 5)
    {
        Serial.println((String)*_canError);
    }
}
