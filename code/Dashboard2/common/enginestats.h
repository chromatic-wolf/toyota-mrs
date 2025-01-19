#ifndef ENGINESTATS_H
#define ENGINESTATS_H

class EngineStats
{
public:

    const double GAS_CONSTANT = 287.0;

    //calculates Brake Mean Effective Pressure in BAR
    double BMEP_Calculator(int revolutionPerPowerStroke = 2, double torqueNm = 0, double displacementCC = 0);

    //Converts RPM to radions per second
    double rpmToRadPerSec(double rpm);

    //Returns power in KW
    double power_Calculator(double torqueNm, double RPM);

    //calculates torque in Nm based of the volumetric efficiency model and mass airflow. (will expand this model later to take into account coolant temp and other factors)
    double calculateTorque(double volumetricEfficiency, double massAirFlow, double intakeTempCelsius, double rpm);

    //calculates the brake specific fuel consumption
    double BSFC_Calculator(double powerKw, double fuelConsumptionGramsPerSecond);

    //Calculates the pressure ratio as a value
    double pressureRatio_Calculator(double pre_turbine_pressure, double post_turbine_pressure);

    //converts a megapascal to bar pressure
    double megaPascalToBar(double megaPascal);

    //converts dedgrees to kelvin
    double degreesToKelvin(double degrees);


private:

};

#endif // ENGINESTATS_H
