#ifndef WHEEL_H
#define WHEEL_H

#include <QWidget>

class Wheel : public QWidget
{
    Q_OBJECT
public:
    explicit Wheel(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *e);
    void wheelEvent(QWheelEvent *e);

signals:
    void up();
    void down();
    void clicked();
};

#endif // WHEEL_H
