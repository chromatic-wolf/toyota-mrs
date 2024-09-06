#include "DigitalPin.h"

DigitalPin::DigitalPin(uint8_t pin_ID, int pin_mode)
{
    pinID = std::make_unique<uint8_t>(pin_ID);
    pinMode = std::make_unique<int>(pin_mode);
}

void DigitalPin::setMode(int mode)
{
    *pinMode = mode;
}

int DigitalPin::getMode()
{
    return *pinMode;
}

void DigitalPin::setHigh()
{
    digitalWrite(*pinID, HIGH);
}

void DigitalPin::setLow()
{
    digitalWrite(*pinID, LOW);
}

int DigitalPin::digitalRead()
{
    return Arduino_h::digitalRead(*pinMode);
}
