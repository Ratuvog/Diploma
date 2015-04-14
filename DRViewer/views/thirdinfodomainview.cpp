#include "thirdinfodomainview.h"
#include "ui_thirdinfodomainview.h"

ThirdInfoDomainView::ThirdInfoDomainView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ThirdInfoDomainView)
{
    ui->setupUi(this);
}

ThirdInfoDomainView::~ThirdInfoDomainView()
{
    delete ui;
}
