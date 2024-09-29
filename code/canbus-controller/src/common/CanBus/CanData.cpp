#include "CanData.h"

CanData::CanData()
{
    canFrame = new can_frame();
    _errorStatus = new MCP2515::ERROR();
}

CanData::~CanData()
{
     delete canFrame;
    delete _errorStatus;
}

can_frame CanData::getData()
{
    return *canFrame;
}

void CanData::setData(can_frame canData)
{
    *canFrame = canData;
}

MCP2515::ERROR CanData::getErrorStatus()
{
    return *_errorStatus;
}

void CanData::setErrorStatus(MCP2515::ERROR errorStatus)
{
    *_errorStatus = errorStatus;
}
