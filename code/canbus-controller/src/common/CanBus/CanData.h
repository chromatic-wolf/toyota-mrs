#include <mcp2515.h>

class CanData
{
private:
    struct can_frame *_canFrame;
    MCP2515::ERROR *_errorStatus;

public:
    CanData();
    ~CanData();
    MCP2515::ERROR errorStatus;
    can_frame *getData();
    void setData(can_frame canFrame);

    MCP2515::ERROR getErrorStatus();
    void setErrorStatus(MCP2515::ERROR errorStatus);
};