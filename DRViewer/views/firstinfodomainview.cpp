#include "firstinfodomainview.h"
#include "ui_firstinfodomainview.h"

FirstInfoDomainView::FirstInfoDomainView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FirstInfoDomainView)
{
    ui->setupUi(this);
}

FirstInfoDomainView::~FirstInfoDomainView()
{
    delete ui;
}
