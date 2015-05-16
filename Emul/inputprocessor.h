#ifndef INPUTPROCESSOR_H
#define INPUTPROCESSOR_H

#include <string>
#include "fiber.h"
#include "probe.h"

using namespace std;

class InputProcessor
{
public:
    InputProcessor(const string& filename);

    void close();

    void readFiber(Fiber &fiber);
    void readProbe(Probe &probe);

    bool isValid() const { return m_isValid;}

private:
    bool m_isValid;
};

#endif // INPUTPROCESSOR_H
