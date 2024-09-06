#include "controller.h"
#include <Arduino.h>
#include <SPI.h>     //Library for using SPI Communication
#include <mcp2515.h> //Library for using CAN Communication (https://github.com/autowp/arduino-mcp2515/)
#include "common/Button.h"

Button *button;

Controller::Controller(uint8_t headlight_pin, uint8_t ac_pin, u_int can_id, int CS_PIN, CAN_SPEED can_speed, CAN_CLOCK can_clock)
{
    Serial.println((String) "Setting up controller");
    SPI.begin();
    _canMsg = new can_frame();
    Serial.println((String) "Can frame object created");
    Serial.println((String) "SPI started");
    _mcp2515 = new MCP2515(CS_PIN); // need to give the CS pin of the SPI interface so the can controller knows where to communicate
    Serial.println((String) "MCP2515 initianted");
    _mcp2515->reset();
    Serial.println((String) "mcp2515 rest");
    _mcp2515->setBitrate(can_speed, can_clock); // Sets CAN at speed 500KBPS and Clock 8MHz
    Serial.println((String) "mcp2515 bitrate set to: " + can_speed);
    Serial.println((String) "mcp2515 can clock set to: " + can_clock);
    _mcp2515->setNormalMode();
    _headlight_switch_pin_id = new uint8_t(headlight_pin);
    _ac_value = new uint8_t(ac_pin);
    pinMode(*_headlight_switch_pin_id, INPUT);
    _can_controller_id = new uint(can_id);
    button = new Button(*_headlight_switch_pin_id, 0, 50);
    moistureSensor = new CapMoistureSensor(A0);
    Serial.println("Setup complete");
}

Controller::~Controller()
{
    // delete heap variables here
    delete _canMsg;
    delete _mcp2515;
    delete _headlight_switch_pin_id;
    delete _ac_value;
    delete moistureSensor;
}

void Controller::loop()
{

    if (button->buttonChanged())
    {
        Serial.println((String) "-------button1 changed--------");
        if (button->buttonPressed())
        {
            Serial.println((String) "button1 pressed");
            _canMsg->can_id = static_cast<unsigned char>(*_can_controller_id); // CAN id as 0x036
            _canMsg->can_dlc = 8;                                              // CAN data length as 8
            _canMsg->data[0] = static_cast<unsigned char>(1);      // first byte is the button state
            _canMsg->data[1] = static_cast<unsigned char>('t');                // second byte is potentiometer state
            _canMsg->data[2] = 0x00;                                           // Rest all with 0 if no data
            _canMsg->data[3] = 0x00;
            _canMsg->data[4] = 0x00;
            _canMsg->data[5] = 0x00;
            _canMsg->data[6] = 0x00;
            _canMsg->data[7] = 0x00;
            _mcp2515->sendMessage(_canMsg);
            Serial.println((String) "Message sent");
        }
        else
        {
            Serial.println((String) "button1 depressed");
            _canMsg->can_id = static_cast<unsigned char>(*_can_controller_id); // CAN id as 0x036
            _canMsg->can_dlc = 8;                                              // CAN data length as 8
            _canMsg->data[0] = static_cast<unsigned char>(0);      // first byte is the button state
            _canMsg->data[1] = static_cast<unsigned char>('t');                // second byte is potentiometer state
            _canMsg->data[2] = 0x00;                                           // Rest all with 0 if no data
            _canMsg->data[3] = 0x00;
            _canMsg->data[4] = 0x00;
            _canMsg->data[5] = 0x00;
            _canMsg->data[6] = 0x00;
            _canMsg->data[7] = 0x00;
            _mcp2515->sendMessage(_canMsg);
            Serial.println((String) "Message sent");
        }
    }

if (moistureSensor->humididyChanged())
{
    Serial.println((String) "Moisture perc: " + moistureSensor->getRaw());
}

    
}
