#ifndef WHEEL_H
#define WHEEL_H

#include <QWidget>

class Wheel : public QWidget
{
    Q_OBJECT
public:
    explicit Wheel(QWidget *parent = 0);

protected:
    void wheelEvent(QWheelEvent *e);

signals:
    void up();
    void down();
};

#endif // WHEEL_H
