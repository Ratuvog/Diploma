#ifndef CURSORMODEL_H
#define CURSORMODEL_H

class Reflectogram;

class CursorModel {
public:
    CursorModel(Reflectogram *refl);
    double value() const;

    void setX(double value);
    double x() const;

private:
    double m_x;
    Reflectogram *m_refl;
};

#endif // CURSORMODEL_H
