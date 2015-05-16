#include <iostream>
#include "emulator.h"
#include "consts.h"

ReflectometerEmulator::ReflectometerEmulator(const Fiber &_context,
                                             const Probe &_probe)
    : fiber(_context),
      probe(_probe)
{
}

double ReflectometerEmulator::traceStep() const {
    return TraceResolution / 1000;
}

void ReflectometerEmulator::run()
{
    double beginX = 0, beginY = 0;

    vector<Heterogenity> heterogenities = fiber.getHeterogenities();
    for(int i = 0; i < heterogenities.size(); ++i)
    {
        Heterogenity h = heterogenities[i];
        double beginEvent = h.eventX - beginX;
        for(double stepX = 0; stepX < beginEvent; stepX += traceStep())
        {
            DPoint point;

            point.x = stepX + beginX;
            point.y = - Utils::fluctuation(h.attenuation * stepX, Deviation) + beginY;

            trace.push_back(point);
        }

        DPoint last = trace.back();
        DPoint up;
        up.x = last.x + traceStep();
        up.y = Utils::fluctuation(h.reflection * traceStep(), Deviation) + last.y;
        trace.push_back(up);

        DPoint down;
        down.x = last.x + 2 * traceStep();
        down.y = -Utils::fluctuation(h.attenuation * traceStep(), Deviation) + last.y - h.loss;
        trace.push_back(down);

        beginX = down.x;
        beginY = down.y;
    }

    for (double stepX = 0; stepX < NoiseLength; stepX += traceStep())
    {
        DPoint point;

        point.x = stepX + beginX;
        point.y = Utils::fluctuation(beginY - NoiseAvgOffset, NoiseDeviation);

        trace.push_back(point);
    }
}
