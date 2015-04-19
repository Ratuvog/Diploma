#include "reflectogram.h"

void Reflectogram::addPoint(double x, double y) {
    m_x.push_back(x);
    m_y.push_back(y);
}

double Reflectogram::value(double x) const {
    QVector<double>::const_iterator low = std::lower_bound(m_x.begin(), m_x.end(), x);
    QVector<double>::const_iterator up = std::upper_bound(m_x.begin(), m_x.end(), x);

    if (low == m_x.end())
        return 0;

    if (*low == x)
        return m_y[low - m_x.begin()];

    if (up == m_x.end())
        return 0;

    if (up == m_x.begin())
        return 0;

    return (m_y[up - m_x.begin()] + m_y[(--low) - m_x.begin()] ) / 2.;
}

double Reflectogram::beginValue() const
{
    return m_y.front();
}

double Reflectogram::lenght() const
{
    return m_x.back();
}
