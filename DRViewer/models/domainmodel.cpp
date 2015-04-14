#include "domainmodel.h"

DomainModel::DomainModel()
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

QVariant DomainModel::transform(int domain, const QVariant &data) const
{
    switch (domain) {
    case Domain::ThirdInfoWL:
        return data.toString() + " nm SM";
    case Domain::FirstInfoPointA:
    case Domain::FirstInfoPointB:
    case Domain::FirstInfoDistanceAB:
    case Domain::ThirdInfoDR:
        return data.toString() + " km";
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
