#ifndef HETEROGENITYMODEL_H
#define HETEROGENITYMODEL_H

#include <QAbstractItemModel>


class ReflectogramReaderInterface;

class HeterogenityModel : public  QAbstractTableModel
{
public:
    explicit HeterogenityModel();

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    enum ModelColumns{
        NumberColumn,
        DistanceColumn,
        TypeColumn,
        LossColumn,
        ReflectanceColumn,
        FiberLossColumn,
        TotalLossColumn,
        ColumnCount
    };

    enum HeterogenityType {
        Reflective,
        NonReflective,
        Grouped,
        FarEnd,
        Other
    };

    struct HeterogenityItem
    {
        double dist;
        HeterogenityType type;
        double loss;
        double reflectance;
        double fiberLoss;
        double totalLoss;
    };

private:

private:
    QList<HeterogenityItem> items;
};

#endif // HETEROGENITYMODEL_H
