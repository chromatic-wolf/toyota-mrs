#include "Button.h"
#include <memory>

Button::Button(uint8_t button_pin, int button_state, unsigned long debounce_delay)
{
    buttonPin = std::make_unique<uint8_t>(button_pin);
    buttonState = std::make_unique<int>(button_state);
    debounceDelay = std::make_unique<unsigned long>(debounce_delay);
    lastDebounceTime = std::make_unique<unsigned long>();
}

Button::~Button()
{
}

bool Button::buttonToggled()
{
    return true;
}

bool Button::buttonPressed()
{
    buttonChanged();
    if (*buttonState == 1)
    {
        return true;
    }
    return false;
}

bool Button::buttonChanged()
{

    int reading = digitalRead(*buttonPin);
    if (*buttonState != reading)
    {
        if ((millis() - *lastDebounceTime) > *debounceDelay)
        {

            *buttonState = reading;
            *lastDebounceTime = millis();
            return true;
        }
    }
    return false;
}