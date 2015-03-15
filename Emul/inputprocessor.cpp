#include <cstdio>
#include <iostream>
#include "inputprocessor.h"

InputProcessor::InputProcessor(const string &filename)
{
    freopen(filename.data(), "r", stdin);
}

void InputProcessor::close()
{
    fclose(stdin);
}

void InputProcessor::readFiber(Fiber &fiber)
{
    double lenght = 0.;
    cin >> lenght;
    fiber.setLength(lenght);

    int keyPointsCount = 0;
    cin >> keyPointsCount;
    for(int i = 0; i < keyPointsCount; ++i)
    {
        double x, a, r;
        cin >> x >> a >> r;
        fiber.addHeterogenity(x, FiberHeterogenity(a, r));
    }
}

void InputProcessor::readProbe(Probe &probe)
{
    double duration = 0.;
    cin >> duration;
    probe.setPulseDuration(duration * 1e-9);

    double avgTime = 0.;
    cin >> avgTime;
    probe.setAveragingTime(avgTime);
}
