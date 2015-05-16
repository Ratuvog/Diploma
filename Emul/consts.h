#ifndef CONSTS_H
#define CONSTS_H

#include <random>

using namespace std;

namespace
{
    const double Deviation = 2e-2;
    const double LightSpeed = 299792.; // km/sec
    const double TraceResolution = 5; // meters

    const double NoiseLength = 15; // km
    const double NoiseAvgOffset = 6; // dB
    const double NoiseDeviation = 0.6;

    default_random_engine generator;
}


class Utils
{
public:
    static double fluctuation(double mean, double dev);
};

#endif // CONSTS_H`
