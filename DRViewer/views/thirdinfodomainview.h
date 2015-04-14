#ifndef THIRDINFODOMAINVIEW_H
#define THIRDINFODOMAINVIEW_H

#include "abstractdomainview.h"

namespace Ui {
class ThirdInfoDomainView;
}

class ThirdInfoDomainView : public AbstractDomainView
{
    Q_OBJECT

public:
    explicit ThirdInfoDomainView(QWidget *parent = 0);
    ~ThirdInfoDomainView();
private:
    void update(int domain);
    void updateAll();
private:
    Ui::ThirdInfoDomainView *ui;
};

#endif // THIRDINFODOMAINVIEW_H
