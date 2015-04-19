#ifndef CURSORMODEL_H
#define CURSORMODEL_H

#include <qobject.h>

class Reflectogram;

class CursorModel : public QObject {
    Q_OBJECT
public:
    CursorModel(Reflectogram *refl);
    double value() const;
    double loss() const;

    void setX(double value);
    double x() const;

signals:
    void updated();

private:
    double m_x;
    Reflectogram *m_refl;
};

#endif // CURSORMODEL_H
