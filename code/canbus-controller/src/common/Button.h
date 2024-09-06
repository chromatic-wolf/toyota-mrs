#include <Arduino.h>
#include <memory>
class Button
{
private:
    std::unique_ptr<uint8_t> buttonPin;
    std::unique_ptr<int> buttonState;
    std::unique_ptr<unsigned long> debounceDelay;
    std::unique_ptr<unsigned long> lastDebounceTime;

public:
    Button(uint8_t button_pin, int button_state = 0, unsigned long debounce_delay = 50);
    ~Button();

    bool buttonPressed();
    bool buttonToggled();
    bool buttonChanged();
    
};