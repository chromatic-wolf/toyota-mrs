#include "common/CanBus/CanBusController.h"

class IndicatorMain
{
private:
    CanBusController *_canController;
    void loop();
    void setup();

public:
    ~IndicatorMain();
    void start();
};