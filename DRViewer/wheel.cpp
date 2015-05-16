#include <qevent.h>
#include <QDebug>
#include "wheel.h"

Wheel::Wheel(QWidget *parent)
    : QWidget(parent)
{

}

void Wheel::mousePressEvent(QMouseEvent *)
{
    emit clicked();
}

void Wheel::wheelEvent(QWheelEvent *e)
{
    int delta = e->delta();
    if (delta < 0)
        emit down();
    else if (delta > 0)
        emit up();
}

