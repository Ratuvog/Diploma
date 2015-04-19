#include "abstractdomainview.h"

AbstractDomainView::AbstractDomainView(QWidget *parent)
    : QWidget(parent),
      m_model(0)
{

}

void AbstractDomainView::disconnectModel()
{
    if (m_model)
    {
        m_model->disconnect(SIGNAL(dataChanged(QModelIndex,QModelIndex)),
                   this, SLOT(dataChanged(QModelIndex,QModelIndex)));
    }
}

void AbstractDomainView::setModel(QAbstractItemModel *model)
{
    disconnectModel();
    m_model = model;
    connect(m_model, SIGNAL(dataChanged(QModelIndex,QModelIndex)),
            this, SLOT(dataChanged(QModelIndex,QModelIndex)));
    updateAll();
}

void AbstractDomainView::dataChanged(const QModelIndex &begin, const QModelIndex &end)
{
    if (begin.isValid())
        update(begin.row());
}

QAbstractItemModel *AbstractDomainView::model() const
{
    return m_model;
}
