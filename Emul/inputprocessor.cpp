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
    int range;
    cin >> range;

    int keyPointsCount = 0;
    cin >> keyPointsCount;
    for(int i = 0; i < keyPointsCount; ++i)
    {
        Heterogenity event;
        cin >> event.eventX >> event.loss >> event.reflection >> event.attenuation;
        fiber.addHeterogenity(event);
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
