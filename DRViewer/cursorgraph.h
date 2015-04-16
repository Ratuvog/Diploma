#ifndef CURSORGRAPH_H
#define CURSORGRAPH_H

#include "cursormodel.h"
#include "qcustomplot.h"
#include "reflectogram.h"

class CursorGraph {
public:
    CursorGraph(QCPGraph *graph, CursorModel *c, const QString &label);
    ~CursorGraph();

    void updateGraph();

    double moveStep() const;
    void move(double step);

    void select();
    void unselect();

    CursorModel *model() const { return m_cursor; }
    QString labelText() const { return m_label->text(); }

private:
    QCPGraph *m_graph;
    QCPItemText *m_label;
    CursorModel *m_cursor;
};

#endif // CURSORGRAPH_H
