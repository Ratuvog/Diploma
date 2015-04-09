#ifndef FRAME_H
#define FRAME_H

#include <QWidget>

namespace Ui {
    class Frame;
}

class QCustomPlot;

class Frame : public QWidget
{
    Q_OBJECT
public:
    explicit Frame(QWidget *parent = 0);
    ~Frame();

    void readData();
    void setup(QCustomPlot *customPlot);

signals:

public slots:

private:
    typedef QPair<QVector<double>, QVector<double> > Coords;
    Coords data;
    Ui::Frame *ui;
};

#endif // FRAME_H
