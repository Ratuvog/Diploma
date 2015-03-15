#include <iostream>
#include "emulator.h"
#include "inputprocessor.h"
#include "outputprocessor.h"

using namespace std;

struct Faker
{
    static Fiber fiber()
    {
        Fiber f;
        f.setLength(85);
        f.setAtteniation(0.24);
        return f;
    }

    static Probe probe()
    {
        Probe p;
        p.setAveragingTime(1);
        p.setInputPulsePower(0);
        p.setPulseDuration(5 * 1e-9);
        return p;
    }
};

int main()
{
    Fiber fiber = Faker::fiber();
    Probe probe = Faker::probe();

    const string inputFile = "/home/ratuvog/settings.txt";
    InputProcessor ip(inputFile);
    ip.readFiber(fiber);
    ip.readProbe(probe);

    ReflectometerEmulator emul(fiber, probe);
    emul.run();

    const string outputFile = "/home/ratuvog/input.txt";
    OutputProcessor op(outputFile);
    op.writeTrace(emul.getTrace());
    op.close();

    return 0;
}

