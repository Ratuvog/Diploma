#ifndef ABSTRACTDOMAINMODEL
#define ABSTRACTDOMAINMODEL

#include <qabstractitemmodel.h>

class AbstractDomainModel : public QAbstractTableModel
{
public:
    int columnCount(const QModelIndex &) const
    {
        return 1;
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const
    {
        return m_data.size();
    }

    QVariant data(const QModelIndex &index, int) const
    {
        if (!index.isValid())
            return QVariant();
        if (index.row() < 0 || index.row() >= rowCount())
            return QVariant();

        return m_data[index.row()];
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

    void initialize(QHash<int, QVariant> data) { m_data = data; }

private:
    QHash<int, QVariant> m_data;

};

#endif // ABSTRACTDOMAINMODEL

