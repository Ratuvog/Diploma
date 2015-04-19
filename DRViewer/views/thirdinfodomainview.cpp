#include "thirdinfodomainview.h"
#include "ui_thirdinfodomainview.h"
#include "models/domains.h"

ThirdInfoDomainView::ThirdInfoDomainView(QWidget *parent) :
    AbstractDomainView(parent),
    ui(new Ui::ThirdInfoDomainView)
{
    ui->setupUi(this);
}

ThirdInfoDomainView::~ThirdInfoDomainView()
{
    delete ui;
}

void ThirdInfoDomainView::update(int domain)
{
    using namespace Domain;
    QString display = model()->data(model()->index(domain, 0)).toString();
    switch (domain) {
        case ReflectogramWaveLenght:  ui->wl->setText(display); break;
        case ReflectogramLineLenght:  ui->dr->setText(display); break;
        case ThirdInfoPW:  ui->pw->setText(display); break;
        case ThirdInfoIOR: ui->ior->setText(display); break;
        case ThirdInfoRES: ui->res->setText(display); break;
        case ThirdInfoAVG: ui->avg->setText(display); break;
        default: break;
    }
}

void ThirdInfoDomainView::updateAll()
{
    for(int i = Domain::ReflectogramWaveLenght; i < Domain::ThirdInfoDomainsEnd; ++i)
        update(i);
}
