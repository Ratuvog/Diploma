#include <cmath>
#include "fiber.h"

Fiber::Fiber()
    : length(0),
      attenuation(0)
{
}

void Fiber::addHeterogenity(double x, const FiberHeterogenity &het)
{
    heterogenities[x] = het;
}

double Fiber::getAttenuation(double x, double eps) const
{
    map<double, FiberHeterogenity>::const_iterator it;
    it = heterogenities.lower_bound(x);
    if (it != heterogenities.cend() && abs(it->first - x) < eps)
        return - it->second.reflection + attenuation;
    return attenuation;
}

double Fiber::getAttenuationIncrease(double x, double eps) const
{
    map<double, FiberHeterogenity>::const_iterator it;
    it = heterogenities.lower_bound(x);
    if (it != heterogenities.cend() && abs(it->first - x) < eps)
        return - it->second.attenuation;
    return 0;
}
