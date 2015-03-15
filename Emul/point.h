#ifndef POINT_H
#define POINT_H

struct DPoint
{
    double x, y;
    DPoint(double _x = 0., double _y = 0.)
        : x(_x), y(_y)
    {
    }
};

#endif // POINT_H
