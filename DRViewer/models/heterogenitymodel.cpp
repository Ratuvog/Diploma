#include "heterogenitymodel.h"

HeterogenityModel::HeterogenityModel()
{
}

int HeterogenityModel::rowCount(const QModelIndex &) const
{
    return items.count();
}

int HeterogenityModel::columnCount(const QModelIndex &) const
{
    return ColumnCount;
}

QVariant HeterogenityModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() < 0 && index.row() >= items.count())
        return QVariant();

    const HeterogenityItem &item = items[index.row()];

    if (role == Qt::DisplayRole)
    {
        switch (index.column())
        {
        case NumberColumn: return index.column() + 1;
        case DistanceColumn: return item.dist;
        case TypeColumn: return item.type;
        case LossColumn: return item.loss;
        case ReflectanceColumn: return item.reflectance;
        case FiberLossColumn: return item.fiberLoss;
        case TotalLossColumn: return item.totalLoss;
        default:
            break;
        }
    }
    return QVariant();
}

QVariant HeterogenityModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case NumberColumn: return "No";
            case DistanceColumn: return "Dist(km)";
            case TypeColumn: return "Type";
            case LossColumn: return "Loss(dB)";
            case ReflectanceColumn: return "Reflect(dB)";
            case FiberLossColumn: return "dB/km";
            case TotalLossColumn: return "Cum.Loss(dB)";
            }
        }
    }
    return QVariant();
}

