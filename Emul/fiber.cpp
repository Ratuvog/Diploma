#include <cmath>
#include "fiber.h"

Fiber::Fiber() : range(0) {}

void Fiber::addHeterogenity(const Heterogenity &het)
{
    heterogenities.push_back(het);
}

vector<Heterogenity> Fiber::getHeterogenities() const
{
    return heterogenities;
}
