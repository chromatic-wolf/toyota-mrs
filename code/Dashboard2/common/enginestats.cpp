#include "enginestats.h"
#include <math.h>

//retures BMEP in BAR
//(2 x pi x revolutions per power stroke (2) x torque (nm) ) / displacement = BMEP in mega pascals
double EngineStats::BMEP_Calculator(int revolutionPerPowerStroke, double torqueNm, double displacementCC)
{
    return (megaPascalToBar((2* M_PI * revolutionPerPowerStroke * torqueNm)/displacementCC));
}

double EngineStats::rpmToRadPerSec(double rpm)
    {
    return rpm *0.10472;
    }

double EngineStats::power_Calculator(double torqueNm, double RPM)
{
    return torqueNm* rpmToRadPerSec(RPM);
}

double EngineStats::BSFC_Calculator(double powerKw, double fuelConsumptionGramsPerSecond)
{
    //Fuel consumption in grams per second / power in watts
    return fuelConsumptionGramsPerSecond/ (powerKw/1000);
}

double EngineStats::pressureRatio_Calculator(double pre_turbine_pressure, double post_turbine_pressure)
{
    return pre_turbine_pressure / post_turbine_pressure;
}

double EngineStats::megaPascalToBar(double megaPascal)
{
    return megaPascal*10;
}
