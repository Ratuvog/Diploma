#include <iostream>
#include "emulator.h"
#include "consts.h"

ReflectometerEmulator::ReflectometerEmulator(const Fiber &_context,
                                             const Probe &_probe)
    : fiber(_context),
      probe(_probe)
{
}

void ReflectometerEmulator::run()
{
    const int noiseSize = NoiseLength / probe.getPulseDuration() / LightSpeed;
    const int traceSize = fiber.getLength() / probe.getPulseDuration() / LightSpeed;
    trace.resize(traceSize+noiseSize);

    const double traceResolution = fiber.getLength() / traceSize;
    double step = 0;
    for(int i = 0; i < traceSize; ++i)
    {
        DPoint p;
        p.x = (double)(i + 1) * traceResolution;
        p.y = -Utils::fluctuation(fiber.getAttenuation(p.x, traceResolution), Deviation) * p.x;
        step += fiber.getAttenuationIncrease(p.x, traceResolution);
        p.y += probe.getInputPulsePower() + step;
        trace[i] = p;
    }

    for(int i = traceSize; i < traceSize+noiseSize; ++i)
    {
        DPoint p;
        p.x = (double)(i + 1) * traceResolution;
        p.y = Utils::fluctuation(trace[traceSize-1].y - NoiseAvgOffset, NoiseDeviation);
        trace[i] = p;
    }

}
