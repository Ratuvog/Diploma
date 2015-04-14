#include "menudomainmodel.h"
#include "models/domains.h"

MenuDomainModel::MenuDomainModel()
{
    using namespace Domain;
    QHash<int, QVariant> data;

    data[Menu1thButtonLabel] = "Manual Test";
    data[Menu1thButtonValue] = "Off";
    data[Menu2thButtonLabel] = "Real Time";
    data[Menu2thButtonValue] = "Off";
    data[Menu3thButtonLabel] = "Wavelength";
    data[Menu3thButtonValue] = "1550";
    data[Menu4thButtonLabel] = "Range / Pulse width";
    data[Menu4thButtonValue] = "100 km / 4 us [HR]";
    data[Menu5thButtonLabel] = "Display From";
    data[Menu5thButtonValue] = "Origin";
    data[Menu6thButtonLabel] = "More >>";
    data[Menu6thButtonValue] = "";

    initialize(data);
}



