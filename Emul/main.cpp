#include <iostream>
#include "emulator.h"
#include "inputprocessor.h"
#include "outputprocessor.h"

using namespace std;

struct Faker
{
    static Fiber fiber()
    {
        return Fiber();
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
    cerr << "Reading configure file..." << endl;
    InputProcessor ip(inputFile);
    ip.readFiber(fiber);
    ip.readProbe(probe);
    cerr << "Input file is valid " << endl << endl;
    cerr << "Running emulation..." << endl;
    ReflectometerEmulator emul(fiber, probe);
    emul.run();
    cerr << "Emulation successful done. Reflectogram has " << emul.getTrace().size() << " points" << endl;
    cerr << endl;
    cerr << "Write output file..." << endl;
    const string outputFile = "/home/ratuvog/input.txt";
    OutputProcessor op(outputFile);
    op.writeTrace(emul.getTrace());
    cerr << "Output file was created" << endl;
    cerr << "Done. Return code: " << endl << 0 << endl;
    op.close();
    return 0;
}

