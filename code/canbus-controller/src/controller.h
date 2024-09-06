#include <Arduino.h>
#include <SPI.h>          //Library for using SPI Communication 
#include <mcp2515.h> 
#include "common/CapMoistureSensor.h"

class Controller
{
private:
struct can_frame *_canMsg;
MCP2515 *_mcp2515; // change this to the CS pin of whatever board you have
uint8_t* _headlight_switch_pin_id;
uint8_t *_ac_value;
u_int *_can_controller_id;
CapMoistureSensor *moistureSensor;

public:
    Controller(uint8_t headlight_pin, uint8_t ac_pin, u_int can_id, int CS_PIN, CAN_SPEED can_speed = CAN_1000KBPS, CAN_CLOCK can_clock = MCP_8MHZ);
    ~Controller();
    void loop();
};