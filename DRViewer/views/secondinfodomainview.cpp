#include "secondinfodomainview.h"
#include "ui_secondinfodomainview.h"

SecondInfoDomainView::SecondInfoDomainView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SecondInfoDomainView)
{
    ui->setupUi(this);
}

SecondInfoDomainView::~SecondInfoDomainView()
{
    delete ui;
}
