#include "cursormodel.h"
#include "reflectogram.h"

CursorModel::CursorModel(Reflectogram *refl)
    : m_x(0), m_refl(refl)
{
}

double CursorModel::value() const
{
    return m_refl->value(m_x);
}

double CursorModel::loss() const
{
    if (x() == 0)
        return 0;

    return qAbs(m_refl->beginValue() - value()) / x();
}

void CursorModel::setX(double value)
{
    m_x = value;
    emit updated();
}

double CursorModel::x() const {
    return m_x;
}
