#include "fakeengine.h"
#include <random>
#include <QString>
#include <iostream>


fakeEngine::fakeEngine(QObject *parent)
    : QObject{parent}
{}

//random example VE map
double veTable[15][20]=
    {
        {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
        {15, 15, 15, 15, 18, 19, 20, 22, 22, 22, 22, 28, 28, 28, 28, 28, 28, 28, 28, 28},
        {20, 20, 20, 20, 22, 23.5, 25, 28, 28, 26, 26, 31, 31, 31, 31, 31, 31, 31, 31, 31},
        {20, 20, 20, 20, 22, 27, 27, 27, 30, 30, 29, 30, 30, 30, 30, 30, 30, 30, 30, 30},
        {25.5, 25.5, 25.5, 25.5, 25.5, 25.5, 28.5, 28.5, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30},
        {27, 27, 27, 27, 27, 27, 29.5, 30.2, 30.8, 31.5, 31.5, 35, 34, 33, 33, 33, 33, 33, 33, 33},
        {27.5, 27.5, 27.5, 27.5, 27.5, 27.5, 31, 31, 32, 32, 33, 37.5, 37, 37.5, 39, 39, 39, 39, 39, 39},
        {29, 29, 29, 29, 29, 29, 33, 34, 35.5, 35.5, 36, 40, 41, 41, 42, 42, 42, 42, 42, 42},
        {32, 32, 32, 32, 32, 32, 35.3, 36.5, 38.5, 38.5, 38.5, 43, 44, 45, 46, 46, 46, 46, 46, 46},
        {37.3, 37.3, 37.3, 37.3, 37.3, 37.3, 37.3, 37.5, 40, 40, 42, 45, 47, 48, 48, 48, 48, 48, 48, 48},
        {39.5, 39.5, 39.5, 39.5, 39.5, 39.5, 39.5, 39.5, 42, 42, 44, 48, 50, 51, 50, 50, 50, 50, 50, 50},
        {41, 41, 41, 41, 41, 41, 41, 41, 45, 45, 46, 50, 52, 52, 52, 52, 52, 52, 52, 52},
        {41, 41, 41, 41, 41, 41, 41, 41, 45, 45, 46, 51, 52, 52, 52, 52, 52, 52, 52, 52},
        {47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 51, 52, 53, 53, 53, 53, 53, 53, 53},
        {49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 52, 53, 53, 53, 53, 53, 53, 53, 53}
};

// ve table rpm column
std::vector<double> rpmMap = {0.0,500.0,1000.0,1500.0,2000.0,2500.0,3000.0,3500.0,4000.0,4500.0,5000.0,5500.0,6000.0,6500.0,7000.0,7500.0,8000.0,8500.0,9000.0,1000.0};

//ve table pressure rows
std::vector<double> pressureMapBar = {0.15, 0.3, 0.45, 0.6, 0.75,0.9, 1.05, 1.2, 1.35, 1.5, 1.65, 1.8, 1.95, 2.1, 2.25};


bool enigneStarted = false;
double currentManifoldPressure;
double currentRPM;
double currentVE;

std::random_device rd;


double generateRandomValue() {
    // Create a random number generator with a random seed
    std::mt19937 gen(rd());

    // Define a uniform distribution in the range [0.0, 1.0)
    std::uniform_real_distribution<> dis(0.0, 1.0);

    // Generate and return a random value between 0 and 1
    return dis(gen);
}

//function to find the closest value in a array
int findClosestIndex(const std::vector<double>& vec, double target) {
    int closestIndex = 0;
    int minDifference = std::abs(vec[0] - target); // Start with the first element

    // Iterate through the vector to find the closest value
    for (int i = 1; i < vec.size(); i++) {
        int diff = std::abs(vec[i] - target); // Calculate absolute difference from target
        if (diff < minDifference) {
            minDifference = diff;
            closestIndex = i;
        }
    }

    return closestIndex;
}

double mapRange(double x, double min, double max, double outMin, double outMax) {


    return ((x - min) / (max - min)) * (outMax - outMin) + outMin;
}

//returns the current VE
double fakeEngine::getCurrentVE(double rpm, double pressureBar)
{
    int currentPosRpm = findClosestIndex(rpmMap, rpm);
    int currentPosPressure = findClosestIndex(pressureMapBar, pressureBar);
    return veTable[currentPosPressure][currentPosRpm];
}

//This function will tick the engine over so every time it is called some random "algorithm" will move the core engine values (rpm and load probably) in order to test the GUI systems ect.
//Load is based on RPM and manifold pressure so makes sense to move these values and everything else should be derived from those.
void fakeEngine::tickEngine()
{
    //if engine is just started aka first tick then set load and rpm to lowest value.
    if (enigneStarted == false)
    {
        std::cout << "Engine just started" << std::endl;
        currentManifoldPressure = 0.15;
        currentRPM = 500;
        enigneStarted = true;
    }

    currentVE = getCurrentVE(currentRPM, currentManifoldPressure);
    emit getPressure(currentManifoldPressure);
    emit getRpm(currentRPM);
    emit getCurrentVe(currentVE);

    std::cout << "Engine RPM: " << currentRPM << std::endl;
    std::cout << "Engine Pressure: " << currentManifoldPressure << std::endl;

}

void fakeEngine::adjustPressure(int value)
{
    //std::cout << static_cast<int>(mapRange(value,0,100,0,14)) << '\n';
    currentManifoldPressure = pressureMapBar[static_cast<int>(mapRange(value,0,100,0,14))];
   // std::cout << "Current mani pressure: " << currentManifoldPressure << '\n';
}

void fakeEngine::adjustRpm(int value)
{
    //std::cout << static_cast<int>(mapRange(value,0,100,0,19)) << '\n';
    currentRPM = rpmMap[static_cast<int>(mapRange(value,0,100,0,19))];
   // std::cout << "Current rpm: " << currentRPM << '\n';
}
