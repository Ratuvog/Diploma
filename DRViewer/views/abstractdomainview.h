#ifndef ABSTRACTDOMAINVIEW_H
#define ABSTRACTDOMAINVIEW_H

#include <QAbstractItemModel>
#include <QWidget>

class AbstractDomainView : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractDomainView(QWidget *parent = 0);
    virtual ~AbstractDomainView();

    void setModel(QAbstractItemModel *model);
    QAbstractItemModel *model() const;
protected:
    virtual void update(int domain) = 0;
    virtual void updateAll() = 0;
public slots:
    void dataChanged(const QModelIndex &begin, const QModelIndex &end);
private:
    void disconnectModel();
private:
    QAbstractItemModel *m_model;
};

#endif // ABSTRACTDOMAINVIEW_H
