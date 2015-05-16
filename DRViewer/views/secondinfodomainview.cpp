#include "secondinfodomainview.h"
#include "ui_secondinfodomainview.h"
#include "domains.h"

SecondInfoDomainView::SecondInfoDomainView(QWidget *parent) :
    AbstractDomainView(parent),
    ui(new Ui::SecondInfoDomainView)
{
    ui->setupUi(this);
}

SecondInfoDomainView::~SecondInfoDomainView()
{
    delete ui;
}

void SecondInfoDomainView::update(int domain)
{
    using namespace Domain;
    QString display = model()->data(model()->index(domain, 0)).toString();
    switch (domain) {
        case CursorLoss: ui->loss->setText(display); break;
        case CursorReflect: ui->refl->setText(display); break;
        default: break;
    }
}

void SecondInfoDomainView::updateAll()
{
    for(int i = Domain::CursorLoss; i < Domain::SecondInfoDomainsEnd; ++i)
        update(i);
}
