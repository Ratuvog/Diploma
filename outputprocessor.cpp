#include <cstdio>
#include <iomanip>
#include <iostream>

#include "outputprocessor.h"

OutputProcessor::OutputProcessor(const string &filename)
{
    freopen(filename.data(), "w", stdout);
}

void OutputProcessor::close()
{
    fclose(stdout);
}

void OutputProcessor::writeTrace(const vector<DPoint> &trace)
{
    cout << fixed << setprecision(12);

    cout << trace.size() << endl;
    for(int i = 0; i < trace.size(); ++i)
        cout << trace[i].x << " " << trace[i].y << endl;
}
