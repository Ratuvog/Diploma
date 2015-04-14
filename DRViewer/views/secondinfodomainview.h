#ifndef SECONDINFODOMAINVIEW_H
#define SECONDINFODOMAINVIEW_H

#include "abstractdomainview.h"

namespace Ui {
class SecondInfoDomainView;
}

class SecondInfoDomainView : public AbstractDomainView
{
    Q_OBJECT

public:
    explicit SecondInfoDomainView(QWidget *parent = 0);
    ~SecondInfoDomainView();
private:
    void update(int domain);
    void updateAll();
private:
    Ui::SecondInfoDomainView *ui;
};

#endif // SECONDINFODOMAINVIEW_H
