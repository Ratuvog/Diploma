#ifndef PLOT_H
#define PLOT_H

#include "qcustomplot.h"

class Plot : public QCustomPlot
{
    Q_OBJECT
public:
    Plot(QWidget *parent);
    void setup();

    void addCursor(double x);
    void removeCursor(int i);

    void nextCursor();
    void prevCursor();
    void selectCursor(int i);
    int currentCursor();

    double cursorX();
    void moveUpCursor();
    void moveDownCursor();
signals:
    void cursorUpdated(int number, double x);
private:
    void moveCursor(double step);
private:
    struct Cursor {
        double x;
        QCPGraph *graph;
        Cursor(QCPGraph* graph, double x) : x(x), graph(graph) {}
    };

private:
    QList<Cursor> cursors;
    int m_currentCursor;
};

#endif // PLOT_H
