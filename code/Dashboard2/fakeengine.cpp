#include "fakeengine.h"

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


double rpmMap[20] = {0,500,1000,1500,2000,2500,3000,3500,4000,4500,5000,5500,6000,6500,7000,7500,8000,8500,9000,1000};

double pressureMapBar[15] = {0.15, 0.3, 0.45, 0.6, 0.75,0.9, 1.05, 1.2, 1.35, 1.5, 1.65, 1.8, 1.95, 2.1, 2.25};

bool enigneStarted = false;

double currentManifoldPressure;
double currentRPM;


int find_closest(const vector<double>& A, const double a)
{
    if(A.size() <=0)
        throw std::invalid_argument("empty array");

    const auto lb = std::lower_bound(A.begin(), A.end(), a);
    int ans = lb!= A.end() ? *lb : A.back();
    if (lb != A.begin()) {
        auto prec = lb - 1;
        if (abs(ans - a) > abs(*prec - a))
            ans = *prec;
    }

    return ans;
}




double fakeEngine::getCurrentVE(double rpm, double pressureBar)
{
    int currentPosRpm = find_closest(rpmMap, rpm);
    int currentPosPressure = find_closest(pressureMapBar, pressureBar);
    return veTable[currentPosPressure][currentPosRpm];
}
fakeEngine::fakeEngine() {

}

//This function will tick the engine over so every time it is called some random "algorithm" will move the core engine values (rpm and load probably) in order to test the GUI systems ect.
//Load is based on RPM and manifold pressure so makes sense to move these values and everything else should be derived from those.
void fakeEngine::tickEngine()
{
    //if engine is just started aka first tick then set load and rpm to lowest value.
    if (engineStarted == false)
        {
        currentManifoldPressure = 0.15;
        currentRPM = 500;
        engineStarted = true;
        }
    std::cout << "Moving engine RPM up" << std::endl;

}
