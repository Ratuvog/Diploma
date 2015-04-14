#ifndef ABSTRACTDOMAINMODEL
#define ABSTRACTDOMAINMODEL

#include <qabstractitemmodel.h>
#include "models/domains.h"

class AbstractDomainModel : public QAbstractTableModel
{
protected:
    virtual QVariant transform(int domain, const QVariant &data) const = 0;
    virtual QVariant defaultValue(int domain) const = 0;

public:
    int columnCount(const QModelIndex &) const
    {
        return 1;
    }

    QVariant data(const QModelIndex &index, int) const
    {
        if (!index.isValid())
            return QVariant();
        if (index.row() < 0 || index.row() >= rowCount())
            return QVariant();

        QVariant data = m_data.value(index.row());
        if (!data.isValid())
            return defaultValue(index.row());

        return transform(index.row(), data);
    }

    bool setData(const QModelIndex &index, const QVariant &value, int role)
    {
        if (!index.isValid())
            return false;

        if (index.row() < 0 || index.row() >= rowCount())
            return false;

        m_data[index.row()] = value;
        return QAbstractTableModel::setData(index, value, role);
    }

protected:
    QHash<int, QVariant> m_data;
};

#endif // ABSTRACTDOMAINMODEL

