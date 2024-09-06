#include <memory>
#include <Arduino.h>

class DigitalPin
{
private:
std::unique_ptr<uint8_t> pinID;
std::unique_ptr<int> pinMode;


public:
DigitalPin(uint8_t pin_ID, int mode);
void setMode(int mode);
int getMode();
void setHigh();
void setLow();

int digitalRead();  

};