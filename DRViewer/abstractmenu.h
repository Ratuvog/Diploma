#ifndef ABSTRACTMENU_H
#define ABSTRACTMENU_H

#include <QWidget>

namespace Ui {
class AbstractMenu;
}

class AbstractMenu : public QWidget
{
    Q_OBJECT

public:
    explicit AbstractMenu(QWidget *parent = 0);
    ~AbstractMenu();

private:
    Ui::AbstractMenu *ui;
};

#endif // ABSTRACTMENU_H
