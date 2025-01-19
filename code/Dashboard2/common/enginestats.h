#ifndef ENGINESTATS_H
#define ENGINESTATS_H

class EngineStats
{
public:
    EngineStats();

    //retures BMEP in BAR
    double BMEP_Calculator(int revolutionPerPowerStroke = 2, double torqueNm = 0, double displacementCC = 0);


    double rpmToRadPerSec(double rpm);


    double powerCalculator(double torqueNm, double RPM);


    double BSFC_Calculator(double powerKw, double fuelConsumptionGramsPerSecond);


private:

};

#endif // ENGINESTATS_H
