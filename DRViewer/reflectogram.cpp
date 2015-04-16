#include "reflectogram.h"

void Reflectogram::addPoint(double x, double y) {
    m_x.push_back(x);
    m_y.push_back(y);
}

double Reflectogram::value(double x) const {
    for (int i = 0; i < m_x.size(); ++i) {
        if (x == m_x[i])
            return m_y[i];
    }
    return 0;
}
