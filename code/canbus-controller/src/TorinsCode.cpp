#include "TorinsCode.h"
#include <Arduino.h>
#include <mcp2515.h>

can_frame canMsg;
MCP2515 mcp2515(15);
uint can_controller_id(3); // each can controller needs its own id make sure noe share it
MCP2515::ERROR canError;
unsigned long previousMillis = 0;
unsigned long interval = 200;
unsigned long currentMillis;

int i = 0;

TorinsCode::TorinsCode()
{
    // this is your setup function
    Serial.println((String) "Setting up Torins Controller");
    SPI.begin();
    Serial.println((String) "SPI started");

    Serial.println((String) "MCP2515 initianted");
    mcp2515.reset();
    Serial.println((String) "mcp2515 rest");
    mcp2515.setBitrate(CAN_1000KBPS, MCP_8MHZ); // Sets CAN at speed 500KBPS and Clock 8MHz
    Serial.println((String) "mcp2515 bitrate set to: " + CAN_1000KBPS);
    Serial.println((String) "mcp2515 can clock set to: " + MCP_8MHZ);
    mcp2515.setNormalMode();
    Serial.println("Setup complete");
}

void TorinsCode::loop()
{
    // This is your main loop

    if (i >= 10000) // resets i to 0 every 10 secs or so (so you can see in ecu the value changing up and down)
    {
        i = 0;
    }

    currentMillis = millis();
    if (currentMillis - previousMillis > interval)
    { // wait one second (this doesnt block unlike the delay function)

        // this is how you send a message
        Serial.println((String) "Sending data");
        previousMillis = currentMillis;
        canMsg.can_id = static_cast<unsigned char>(can_controller_id); // CAN id as 3
        canMsg.can_dlc = 8;                                            // CAN data length as 8
        canMsg.data[0] = static_cast<unsigned char>(i);                // first byte is a mock RPM signal
        canMsg.data[1] = 0x00;
        canMsg.data[2] = 0x00; // Rest all with 0 if no data
        canMsg.data[3] = 0x00;
        canMsg.data[4] = 0x00;
        canMsg.data[5] = 0x00;
        canMsg.data[6] = 0x00;
        canMsg.data[7] = 0x00;
        mcp2515.sendMessage(&canMsg);
        Serial.println((String) "Message sent");

        i = i + 200; // move i up one
    }

    // this is how you send a message.
    canError = mcp2515.readMessage(&canMsg);
    if (canError == MCP2515::ERROR_OK)
    {
        Serial.println((String) "Data received");
        Serial.println((String) "From ID: " + canMsg.can_id);
        Serial.println((String) "Length: " + canMsg.can_dlc);
        Serial.println((String) "Bit 1: " + canMsg.data[0]);
        Serial.println((String) "Bit 2: " + canMsg.data[1]);
        Serial.println((String) "Bit 3: " + canMsg.data[2]);
        Serial.println((String) "Bit 4: " + canMsg.data[3]);
        Serial.println((String) "Bit 5: " + canMsg.data[4]);
        Serial.println((String) "Bit 6: " + canMsg.data[5]);
        Serial.println((String) "Bit 7: " + canMsg.data[6]);
        Serial.println((String) "Bit 8: " + canMsg.data[7]);
        
    }
    else if (canError < 5)
    {
        Serial.println((String) "CAN ERROR: " + canError);
    }
}
