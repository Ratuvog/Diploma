#ifndef FIRSTINFODOMAINVIEW_H
#define FIRSTINFODOMAINVIEW_H

#include "abstractdomainview.h"

namespace Ui {
class FirstInfoDomainView;
}

class FirstInfoDomainView : public AbstractDomainView
{
    Q_OBJECT

public:
    explicit FirstInfoDomainView(QWidget *parent = 0);
    ~FirstInfoDomainView();
private:
    void update(int domain);
    void updateAll();
private:
    Ui::FirstInfoDomainView *ui;
};

#endif // FIRSTINFODOMAINVIEW_H
