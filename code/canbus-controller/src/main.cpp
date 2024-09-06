#include <Arduino.h>
#include <SPI.h>     //Library for using SPI Communication
#include <mcp2515.h> //Library for using CAN Communication (https://github.com/autowp/arduino-mcp2515/)
#include "controller.h"
#include "node.h"
#include "TorinsCode.h"

/*
struct can_frame canMsg;
MCP2515 mcp2515(15); // change this to the CS pin of whatever board you have
bool is_transmitter = true;
const int led = 5;
*/

Controller* controller;
Node* node;
TorinsCode* torinsCode;

void setup()
{
  Serial.begin(9600);

Serial.println("_______In main setup___________");
controller = new Controller(5,12,1,15);
//node = new Node(5,2,15);



/*
Each "device" has its own class and depending on which device you want to program you just run its constructor in here which is essentially its "setup function" 
make sure to run only the constructor and loop function of the device you want to program dont run multiple, comment out the devices you dont want to program like seen above this comment section.
Run the devices loop function in the loop section below. You make all your code changes for the device in its class (seperate cpp and .h file). This way code can be shared across devices and you have less projects and less setting up to do.
*/


//torinsCode = new TorinsCode();

}

void loop()
{
controller->loop();
//node->loop();



//torinsCode->loop();
}
