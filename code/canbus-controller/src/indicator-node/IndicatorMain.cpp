#include "IndicatorMain.h"
#include "common/CanBus/CanBusController.h"

void IndicatorMain::loop()
{

}

void IndicatorMain::setup()
{
_canController = new CanBusController(1,15); //this controller ID is 1, cs pin is 15
}

IndicatorMain::~IndicatorMain()
{
    delete _canController;
}

void IndicatorMain::start()
{
    this->setup();
    this->loop();
}
