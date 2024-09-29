#include <mcp2515.h>

class CanData
{
private:
    MCP2515::ERROR *_errorStatus;

public:
    struct can_frame *canFrame;
    CanData();
    ~CanData();
    MCP2515::ERROR errorStatus;
    can_frame getData();
    void setData(can_frame canData);

    MCP2515::ERROR getErrorStatus();
    void setErrorStatus(MCP2515::ERROR errorStatus);
};