#ifndef FAKEENGINE_H
#define FAKEENGINE_H
#include <QObject>
#include <QString>

class fakeEngine : public QObject
{
    Q_OBJECT
public:
    //this class will represent a fake engine that generates somewhat realistic values to be used to debug the dashboard UI and other systems.
    explicit fakeEngine(QObject *parent = nullptr);


    double powerKw;
    double torqueNm;
    double rpm;
    double IAT;
    double LAMBDA;
    double volumetricEfficancy;
    double mapBar;
    double exhaustPressure;
    double exhaustTemp;
    double coolantTemp;
    double throttlePosition;
    double brakePosition;
    double oilPressure;


    double wheelSpeed;
    int gear;
    double FLWheelSpeed;
    double FRWheelSpeed;
    double RLWheelSpeed;
    double RRWheelSpeed;
    double longGForce;
    double latGForce;
    double underBodyPressureFront;
    double underBodyPressureRear;
    double torqueSplitPercentage;

    bool headlight;
    bool indicatorLeft;
    bool indicatorRight;
    bool handBrake;

    double getCurrentVE(double rpm, double pressureBar);




public slots:
    void tickEngine();
    void adjustPressure(int value);
    void adjustRpm(int value);

signals:
    void getRpm(double rpm);
    void getPressure(double pressure);
    void getCurrentVe(double VE);
    void getCurrentTorque(double torqueNm);



};

#endif // FAKEENGINE_H
