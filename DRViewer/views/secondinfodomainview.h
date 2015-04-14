#ifndef SECONDINFODOMAINVIEW_H
#define SECONDINFODOMAINVIEW_H

#include <QWidget>

namespace Ui {
class SecondInfoDomainView;
}

class SecondInfoDomainView : public QWidget
{
    Q_OBJECT

public:
    explicit SecondInfoDomainView(QWidget *parent = 0);
    ~SecondInfoDomainView();

private:
    Ui::SecondInfoDomainView *ui;
};

#endif // SECONDINFODOMAINVIEW_H
