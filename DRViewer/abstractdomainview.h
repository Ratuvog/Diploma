#ifndef ABSTRACTDOMAINVIEW_H
#define ABSTRACTDOMAINVIEW_H

#include <QWidget>

class AbstractDomainView : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractDomainView(QWidget *parent = 0);
    ~AbstractDomainView();

signals:

public slots:
};

#endif // ABSTRACTDOMAINVIEW_H
