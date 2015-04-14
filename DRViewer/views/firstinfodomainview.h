#ifndef FIRSTINFODOMAINVIEW_H
#define FIRSTINFODOMAINVIEW_H

#include <QWidget>

namespace Ui {
class FirstInfoDomainView;
}

class FirstInfoDomainView : public QWidget
{
    Q_OBJECT

public:
    explicit FirstInfoDomainView(QWidget *parent = 0);
    ~FirstInfoDomainView();

private:
    Ui::FirstInfoDomainView *ui;
};

#endif // FIRSTINFODOMAINVIEW_H
