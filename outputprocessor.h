#ifndef OUTPUTPROCESSOR_H
#define OUTPUTPROCESSOR_H

#include <string>
#include <vector>
#include "point.h"

using namespace std;

class OutputProcessor
{
public:
    OutputProcessor(const string& filename);

    void close();
    void writeTrace(const vector<DPoint> &trace);
};

#endif // OUTPUTPROCESSOR_H
