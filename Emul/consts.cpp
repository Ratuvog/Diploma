#include "consts.h"

double Utils::fluctuation(double mean, double dev)
{
    normal_distribution<double> distributor(mean, dev);
    return distributor(generator);
}
