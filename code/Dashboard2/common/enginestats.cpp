#include "enginestats.h"
#include <iostream>
#include <math.h>






EngineStats::EngineStats() {


    //retures BMEP in BAR
    double BMEP_Calculator(int revolutionPerPowerStroke = 2, double torqueNm = 0, double displacementCC = 0)
    {
        return ((2* M_PI * revolutionPerPowerStroke * torqueNm)/displacementCC)10;
    }

    double rpmToRadPerSec(double rpm)
        {
            return rpm 0.10472
        }

    double powerCalculator(double torqueNm, double RPM)
    {
        return torque* rpmToRadPerSec(RPM);
    }

    double BSFC_Calculator(double powerKw, double fuelConsumptionGramsPerSecond)
    {
        //Fuel consumption in grams per second / power in watts
        return fuelConsumptionGramsPerSecond/ (powerKw/1000)
    }



    int main() {
        // Write C++ code here
        double BMEP = (2* M_PI * 2 * 200)/2000;
        std::cout << "BMEP " << BMEP_Calculator(2, 200, 2000);

        return 0;
    }
    //BMEP calculator
    //(2 x pi x revolutions per power stroke (2) x torque (nm) ) / displacement = BMEP in mega pascals


}
