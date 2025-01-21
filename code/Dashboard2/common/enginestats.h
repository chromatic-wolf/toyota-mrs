#ifndef ENGINESTATS_H
#define ENGINESTATS_H

class EngineStats
{
public:


    //calculates Brake Mean Effective Pressure in BAR
    static double BMEP_Calculator(int revolutionPerPowerStroke = 2, double torqueNm = 0, double displacementCC = 0);

    //Converts RPM to radions per second
    static double rpmToRadPerSec(double rpm);

    //Returns power in KW
   static double power_Calculator(double torqueNm, double RPM);

    //calculates torque in Nm based of the volumetric efficiency model and mass airflow. (will expand this model later to take into account coolant temp and other factors)
   static double calculateTorque(double volumetricEfficiency, double massAirFlow, double intakeTempCelsius, double rpm);

    //calculates the mass airflow going into the engine based off of the MAP model
   static double calculateMAF(double absolutePressure, double airTemperature, double engineDisplacement, double volumetricEfficiency, double rpm);

    //calculates the brake specific fuel consumption
   static double BSFC_Calculator(double powerKw, double fuelConsumptionGramsPerSecond);

    //Calculates the pressure ratio as a value
   static double pressureRatio_Calculator(double pre_turbine_pressure, double post_turbine_pressure);

    //converts a megapascal to bar pressure
   static double megaPascalToBar(double megaPascal);

    //converts dedgrees to kelvin
   static double degreesToKelvin(double degrees);


private:

};

#endif // ENGINESTATS_H
