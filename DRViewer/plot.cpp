#include "plot.h"

Plot::Plot(QWidget *parent)
    : QCustomPlot(parent)
{
}

void Plot::setup()
{
    // give the axes some labels:
    xAxis->setLabel("km");
    yAxis->setLabel("dB");

    // set axes ranges, so we see all data:
    xAxis->setRange(0, 100);
    yAxis->setRange(0, -100);

    xAxis2->setVisible(true);
    xAxis2->setTickLabels(false);
    yAxis2->setVisible(true);
    yAxis2->setTickLabels(false);

    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(xAxis, SIGNAL(rangeChanged(QCPRange)), xAxis2, SLOT(setRange(QCPRange)));
    connect(yAxis, SIGNAL(rangeChanged(QCPRange)), yAxis2, SLOT(setRange(QCPRange)));

    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
    //setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}



