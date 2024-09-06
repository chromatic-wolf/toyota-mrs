#include <Arduino.h>
#include <memory>

class CapMoistureSensor
{
private:
    std::unique_ptr<uint8_t> pin;
    std::unique_ptr<int> dry;
    std::unique_ptr<int> wet;
    std::unique_ptr<int> humidity;
    long tempHumidity;

public:
    CapMoistureSensor(uint8_t analog_pin, const int dry_value = 1024, const int wet_value = 602);
    ~CapMoistureSensor();
    void setDryValue(int dryValue);
    void setWetValue(int wetValue);
    long percentHumididy();
    bool humididyChanged();
    int getRaw();
    
};