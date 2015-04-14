#include "menubutton.h"
#include "ui_menubutton.h"

MenuButton::MenuButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuButton)
{
    ui->setupUi(this);
}

MenuButton::~MenuButton()
{
    delete ui;
}
