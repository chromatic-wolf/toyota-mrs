#include <Arduino.h>
#include <SPI.h>          //Library for using SPI Communication 
#include <mcp2515.h> 

class Node
{
private:
struct can_frame *_canMsg;
MCP2515 *_mcp2515; // change this to the CS pin of whatever board you have
int* _relay_pin;
MCP2515::ERROR *_canError;

u_int *_can_controller_id;

public:
    Node(int relay_pin, u_int can_id, int CS_PIN, CAN_SPEED can_speed = CAN_1000KBPS, CAN_CLOCK can_clock = MCP_8MHZ);
    ~Node();
    void loop();
};