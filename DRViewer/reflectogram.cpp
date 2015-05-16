#include "reflectogram.h"

void Reflectogram::addPoint(double x, double y) {
    m_x.push_back(x);
    m_y.push_back(y);
}

double Reflectogram::value(double x) const {

    QVector<double>::const_iterator low;
    double find = x;
    do {
        low = std::lower_bound(m_x.begin(), m_x.end(), find);
        if (low == m_x.end())
            return 0;

        if (low == m_x.begin())
            return 0;

        find = *(--low);
    } while (*low > x);

    QVector<double>::const_iterator up = std::upper_bound(m_x.begin(), m_x.end(), x);
    if (up == m_x.end())
        return 0;

    double y2,y1,x2,x1;
    y2 = m_y[up - m_x.begin()];
    y1 = m_y[low - m_x.begin()];
    x2 = *up;
    x1 = *low;

    if (x2 == x1)
        return 0;

    double k = (y2 - y1) / (x2 - x1);
    double b = y1 - (y2 - y1) / (x2 - x1) * x1;
    return k * x + b;
}

double Reflectogram::beginValue() const
{
    return m_y.front();
}

double Reflectogram::lenght() const
{
    return m_x.back();
}
