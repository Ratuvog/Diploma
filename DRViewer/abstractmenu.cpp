#include "abstractmenu.h"
#include "ui_abstractmenu.h"

AbstractMenu::AbstractMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AbstractMenu)
{
    ui->setupUi(this);
}

AbstractMenu::~AbstractMenu()
{
    delete ui;
}
