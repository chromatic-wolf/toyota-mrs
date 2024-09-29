#include "CanData.h"

CanData::CanData()
{
    _canFrame = new can_frame();
    _errorStatus = new MCP2515::ERROR();
}

CanData::~CanData()
{
     delete _canFrame;
    delete _errorStatus;
}

can_frame *CanData::getData()
{
    return _canFrame;
}

void CanData::setData(can_frame canFrame)
{
    *_canFrame = canFrame;
}

MCP2515::ERROR CanData::getErrorStatus()
{
    return *_errorStatus;
}

void CanData::setErrorStatus(MCP2515::ERROR errorStatus)
{
    *_errorStatus = errorStatus;
}
