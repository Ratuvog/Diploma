#ifndef PLOT_H
#define PLOT_H

#include "qcustomplot.h"

class Plot : public QCustomPlot
{
public:
    Plot(QWidget *parent);
    void setup();
};

#endif // PLOT_H
