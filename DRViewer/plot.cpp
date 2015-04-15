#include "plot.h"

Plot::Plot(QWidget *parent)
    : QCustomPlot(parent),
      m_currentCursor()
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

void Plot::nextCursor()
{
    m_currentCursor++;
    m_currentCursor %= cursors.count();
}

void Plot::prevCursor()
{
    m_currentCursor--;
    m_currentCursor += cursors.count();
    m_currentCursor %= cursors.count();
}

void Plot::selectCursor(int i)
{
    if (i < 0 || i >= cursors.count())
        return;

    m_currentCursor = i;
}

int Plot::currentCursor()
{
    return m_currentCursor;
}

double Plot::cursorX()
{
    if (cursors.count() == 0)
        return 0;

    return cursors[m_currentCursor].x;
}

void Plot::moveUpCursor()
{
    moveCursor(xAxis->tickStep()/20.);
}

void Plot::moveDownCursor()
{
    moveCursor(-xAxis->tickStep()/20.);
}

void Plot::moveCursor(double step)
{
    if (cursors.count() == 0)
        return;

    cursors[m_currentCursor].x += step;
    double x = cursors[m_currentCursor].x;

    QCPGraph *g = cursors[m_currentCursor].graph;
    g->clearData();
    g->addData(x, -65536);
    g->addData(x, 65536);
    replot();

    emit cursorUpdated(m_currentCursor, cursors[m_currentCursor].x);
}

void Plot::addCursor(double x)
{
    cursors.append(Cursor(addGraph(), x));

    graph()->addData(x, -65536);
    graph()->addData(x, 65536);

    QPen pen;
    pen.setWidth(1);
    pen.setColor(QColor(255,0,0));
    graph()->setPen(pen);

    m_currentCursor = cursors.size() - 1;
    replot();
}

void Plot::removeCursor(int i)
{
    if (i < 0 || i >= cursors.count())
        return;

    removeGraph(cursors[i].graph);
    cursors.removeAt(i);

    m_currentCursor = cursors.size() - 1;
    replot();
}



