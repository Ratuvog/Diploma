#ifndef FIBER_H
#define FIBER_H

#include <map>

using namespace std;

struct FiberHeterogenity
{
    double attenuation;
    double reflection;
    FiberHeterogenity(double a = 0., double r = 0.)
        : attenuation(a), reflection(r) {}
};

class Fiber
{
public:
    Fiber();

    //! Длина ОВ в километрах
    double getLength() const { return length; }
    void setLength(double length) { this->length = length; }

    void addHeterogenity(double x, const FiberHeterogenity &het);

    //! Коэффициент затухания ОВ в дБ/км
    double getAttenuation(double x, double eps) const;
    void setAtteniation(double attn) { attenuation = attn; }

    double getAttenuationIncrease(double x, double eps) const;

private:
    double length;
    double attenuation;
    map<double, FiberHeterogenity> heterogenities;
};
#endif // FIBER_H
