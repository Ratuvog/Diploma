#ifndef EMULATOR_H
#define EMULATOR_H

#include <vector>
#include <cmath>
#include <iomanip>
#include "point.h"
#include "fiber.h"
#include "probe.h"

using namespace std;

class ReflectometerEmulator
{
public:
    ReflectometerEmulator(const Fiber &_context, const Probe &_probe);

    const vector<DPoint> &getTrace() const { return trace; }

    void run();

    double traceStep() const;
private:
    Fiber fiber;
    Probe probe;
    vector<DPoint> trace;
};

#endif // EMULATOR_H
