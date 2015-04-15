#include <qevent.h>
#include <QDebug>
#include "wheel.h"

Wheel::Wheel(QWidget *parent)
    : QWidget(parent)
{

}

void Wheel::wheelEvent(QWheelEvent *e)
{
    int delta = e->angleDelta().y();
    if (delta < 0)
        emit down();
    else if (delta > 0)
        emit up();
}

