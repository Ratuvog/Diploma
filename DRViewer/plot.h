#ifndef PLOT_H
#define PLOT_H

#include "qcustomplot.h"

class Plot : public QCustomPlot
{
public:
    Plot(QWidget *parent);
    void setup();
    void scaleX(double f);
    void scaleY(double f);
};

#endif // PLOT_H
