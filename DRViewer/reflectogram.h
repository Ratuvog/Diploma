#ifndef REFLECTOGRAM_H
#define REFLECTOGRAM_H

#include <QVector>

class Reflectogram {
public:
    void addPoint(double x, double y);

    const QVector<double>& keys() const { return m_x; }
    const QVector<double>& values() const { return m_y; }

    double value(double x) const;

private:
    QVector<double> m_x;
    QVector<double> m_y;
};
#endif // REFLECTOGRAM_H
