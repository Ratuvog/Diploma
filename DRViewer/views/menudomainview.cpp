#include "ui_abstractmenu.h"
#include "menudomainview.h"
#include "domains.h"

MenuDomainView::MenuDomainView(QWidget *parent)
    : AbstractDomainView(parent),
      ui(new Ui::AbstractMenu)
{
    ui->setupUi(this);
}

MenuDomainView::~MenuDomainView()
{
    delete ui;
}

void MenuDomainView::update(int domain)
{
    using namespace Domain;
    QString display = model()->data(model()->index(domain, 0)).toString();
    switch (domain) {
        case Menu1thButtonLabel: ui->pushButton->setLabel(display); break;
        case Menu1thButtonValue: ui->pushButton->setValue(display); break;
        case Menu2thButtonLabel: ui->pushButton_2->setLabel(display); break;
        case Menu2thButtonValue: ui->pushButton_2->setValue(display); break;
        case Menu3thButtonLabel: ui->pushButton_3->setLabel(display); break;
        case Menu3thButtonValue: ui->pushButton_3->setValue(display); break;
        case Menu4thButtonLabel: ui->pushButton_4->setLabel(display); break;
        case Menu4thButtonValue: ui->pushButton_4->setValue(display); break;
        case Menu5thButtonLabel: ui->pushButton_5->setLabel(display); break;
        case Menu5thButtonValue: ui->pushButton_5->setValue(display); break;
        case Menu6thButtonLabel: ui->pushButton_6->setLabel(display); break;
        case Menu6thButtonValue: ui->pushButton_6->setValue(display); break;
        default: break;
    }
}

void MenuDomainView::updateAll()
{
    for(int i = Domain::Menu1thButtonLabel; i < Domain::MenuDomainsEnd; ++i)
        update(i);
}


