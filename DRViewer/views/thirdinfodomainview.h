#ifndef THIRDINFODOMAINVIEW_H
#define THIRDINFODOMAINVIEW_H

#include <QWidget>

namespace Ui {
class ThirdInfoDomainView;
}

class ThirdInfoDomainView : public QWidget
{
    Q_OBJECT

public:
    explicit ThirdInfoDomainView(QWidget *parent = 0);
    ~ThirdInfoDomainView();

private:
    Ui::ThirdInfoDomainView *ui;
};

#endif // THIRDINFODOMAINVIEW_H
