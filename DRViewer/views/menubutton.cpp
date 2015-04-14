#include "menubutton.h"
#include "ui_menubutton.h"

MenuButton::MenuButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuButton)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->value->setAttribute(Qt::WA_TransparentForMouseEvents);
}

MenuButton::~MenuButton()
{
    delete ui;
}

void MenuButton::setLabel(const QString &text)
{
    ui->label->setText(text);
}

void MenuButton::setValue(const QString &value)
{
    ui->value->setText(value);
}

void MenuButton::setDisableState(bool state)
{
    ui->button->setDisabled(state);
    ui->value->setDisabled(state);
    ui->label->setDisabled(state);
}
