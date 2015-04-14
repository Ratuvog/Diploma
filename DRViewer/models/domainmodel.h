#ifndef DOMAINMODEL_H
#define DOMAINMODEL_H

#include "abstractdomainmodel.h"

class DomainModel : public AbstractDomainModel
{
public:
    DomainModel();

    int rowCount(const QModelIndex &parent) const;
protected:
    QVariant transform(int domain, const QVariant &data) const;
    QVariant defaultValue(int domain) const;
};

#endif // DOMAINMODEL_H
