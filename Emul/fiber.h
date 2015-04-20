#ifndef FIBER_H
#define FIBER_H

#include "point.h"

#include <vector>

using namespace std;

struct Heterogenity
{
    double eventX;

    double reflection;
    double loss;

    double attenuation;
};

class Fiber
{
public:
    Fiber();

    void addHeterogenity(const Heterogenity &het);
    vector<Heterogenity> getHeterogenities() const;
private:
    double range;
    vector<Heterogenity> heterogenities;
};
#endif // FIBER_H
