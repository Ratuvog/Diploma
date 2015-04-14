#ifndef ABSTRACTMENU_H
#define ABSTRACTMENU_H

#include "abstractdomainview.h"

namespace Ui {
class AbstractMenu;
}

class MenuDomainView : public AbstractDomainView
{
    Q_OBJECT

public:
    explicit MenuDomainView(QWidget *parent = 0);
    ~MenuDomainView();

    void update(int domain);
    void updateAll();

signals:
    void clickToOne();
    void clickToTwo();
    void clickToThree();
    void clickToFour();
    void clickToFive();
    void clickToSix();

private:
    Ui::AbstractMenu *ui;
};

#endif // ABSTRACTMENU_H
