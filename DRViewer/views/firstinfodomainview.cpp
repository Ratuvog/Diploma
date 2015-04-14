#include "firstinfodomainview.h"
#include "models/domains.h"
#include "ui_firstinfodomainview.h"

FirstInfoDomainView::FirstInfoDomainView(QWidget *parent) :
    AbstractDomainView(parent),
    ui(new Ui::FirstInfoDomainView)
{
    ui->setupUi(this);
}

FirstInfoDomainView::~FirstInfoDomainView()
{
    delete ui;
}

void FirstInfoDomainView::update(int domain)
{
    using namespace Domain;
    QString display = model()->data(model()->index(domain, 0)).toString();
    switch (domain) {
        case FirstInfoPointA: ui->pointA->setText(display); break;
        case FirstInfoPointB: ui->pointB->setText(display); break;
        case FirstInfoDistanceAB: ui->distAB->setText(display); break;
        default: break;
    }
}

void FirstInfoDomainView::updateAll()
{
    for(int i = Domain::FirstInfoPointA; i < Domain::FirstInfoDomainsEnd; ++i)
        update(i);
}
