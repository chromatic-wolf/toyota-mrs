#include "CapMoistureSensor.h"

CapMoistureSensor::CapMoistureSensor(uint8_t analog_pin, const int dry_value, const int wet_value)
{
    pin = std::make_unique<uint8_t>(analog_pin);
    dry = std::make_unique<int>(dry_value);
    wet = std::make_unique<int>(wet_value);
    humidity = std::make_unique<int>();
    
}

CapMoistureSensor::~CapMoistureSensor()
{
}

void CapMoistureSensor::setDryValue(int dryValue)
{
    *dry = dryValue;
}

void CapMoistureSensor::setWetValue(int wetValue)
{
    *wet = wetValue;
}

long CapMoistureSensor::percentHumididy()
{
    this->humididyChanged();

    return *humidity;
}

int CapMoistureSensor::getRaw()
{
    this->humididyChanged();
    return analogRead(*pin);
    return 0;
}

bool CapMoistureSensor::humididyChanged()
{
    tempHumidity = map(analogRead(*pin), *wet, *dry, 100, 0);
    if (tempHumidity != *humidity)
    {
        // value changed
        *humidity = tempHumidity;
        return true;
    }
    return false;
}