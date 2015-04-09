#ifndef FRAME_H
#define FRAME_H

#include <QWidget>

class frame : public QWidget
{
    Q_OBJECT
public:
    explicit frame(QWidget *parent = 0);
    ~frame();

signals:

public slots:
};

#endif // FRAME_H
