#include "domainmodel.h"
#include "cursormodel.h"
#include "reflectogram.h"

DomainModel::DomainModel()
    : cursorA(0),
      cursorB(0),
      m_refl(0)
{
    using namespace Domain;

    m_data[Menu1thButtonLabel] = "Manual Test";
    m_data[Menu1thButtonValue] = "Off";
    m_data[Menu2thButtonLabel] = "Real Time";
    m_data[Menu2thButtonValue] = "Off";
    m_data[Menu3thButtonLabel] = "Wavelength";
    m_data[Menu3thButtonValue] = "1550";
    m_data[Menu4thButtonLabel] = "Range / Pulse width";
    m_data[Menu4thButtonValue] = "100 km / 4 us [HR]";
    m_data[Menu5thButtonLabel] = "Display From";
    m_data[Menu5thButtonValue] = "Origin";
    m_data[Menu6thButtonLabel] = "More >>";
    m_data[Menu6thButtonValue] = "";
}

int DomainModel::rowCount(const QModelIndex &) const
{
    return Domain::DomainsEnd;
}

void DomainModel::setReflectogram(Reflectogram *refl)
{
    m_refl = refl;
}

void DomainModel::updateAll()
{
    for(int i = 0; i < Domain::DomainsEnd; ++i) {
        emit dataChanged(index(i, 0), index(i, 0));
    }
}

void DomainModel::setCursorA(CursorModel *model)
{
    cursorA = model;
}

void DomainModel::setCursorB(CursorModel *model)
{
    cursorB = model;
}

QVariant DomainModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() < 0 || index.row() >= rowCount())
        return QVariant();

    QVariant value;
    switch (index.row()) {
    case Domain::CursorPointA:
        if (cursorA)
            value = cursorA->x();
        break;
    case Domain::CursorPointB:
        if (cursorB)
            value = cursorB->x();
        break;
    case Domain::CursorDistanceAB:
        if (cursorA && cursorB)
            value = qAbs(cursorA->x() - cursorB->x());
        break;
    case Domain::CursorReflect:
        if (cursorA)
            value = cursorA->value();
        break;
    case Domain::CursorLoss:
        if (cursorA && cursorB)
            value = qAbs(cursorA->value() - cursorB->value());
        else if (cursorA)
            value = cursorA->loss();
        break;
    case Domain::ReflectogramLineLenght:
        if (m_refl)
            value = m_refl->lenght();
        break;
    default:
        return AbstractDomainModel::data(index, role);
    }

    if (value.isValid())
        return transform(index.row(), value);

    return defaultValue(index.row());
}

QVariant DomainModel::transform(int domain, const QVariant &data) const
{
    switch (domain) {
    case Domain::ReflectogramWaveLenght:
        return data.toString() + " nm SM";
    case Domain::CursorPointA:
    case Domain::CursorPointB:
    case Domain::CursorDistanceAB:
    case Domain::ReflectogramLineLenght:
        return QString::number(data.toDouble(), 'f', 4) + " km";
    case Domain::CursorLoss:
    case Domain::CursorReflect:
        return QString::number(data.toDouble(), 'f', 4);
    case Domain::ThirdInfoPW:
        return data.toString() + " us[HR]";
    default:
        break;
    }

    return data;
}

QVariant DomainModel::defaultValue(int domain) const
{
    return "-----";
}
