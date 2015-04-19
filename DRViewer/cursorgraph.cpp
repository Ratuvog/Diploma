#include "cursorgraph.h"

CursorGraph::CursorGraph(QCPGraph *graph, CursorModel *c, const QString &label)
    : m_graph(graph), m_cursor(c)
{
    m_label = new QCPItemText(m_graph->parentPlot());
    m_graph->parentPlot()->addItem(m_label);

    m_label->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
    m_label->position->setType(QCPItemPosition::ptPlotCoords);
    m_label->setText(label);

    updateGraph();
    unselect();
}

CursorGraph::~CursorGraph() {
    m_graph->parentPlot()->removeItem(m_label);
    m_graph->parentPlot()->removeGraph(m_graph);
    delete m_cursor;
}

void CursorGraph::updateGraph()
{
    m_graph->clearData();
    m_graph->addData(m_cursor->x(), -65536);
    m_graph->addData(m_cursor->x(), 65536);
    m_label->position->setCoords(
        m_cursor->x(),
        m_graph->parentPlot()->yAxis->range().upper
    );
}

double CursorGraph::moveStep() const {
    return m_graph->parentPlot()->xAxis->tickStep()/20.;
}

void CursorGraph::move(double step) {
    m_cursor->setX(m_cursor->x() + step);
    updateGraph();
}

void CursorGraph::select() {
    m_label->setFont(QFont(m_graph->parentPlot()->font().family(), 9));
    m_label->setPen(QPen(Qt::black));

    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::green);
    m_graph->setPen(pen);
}

void CursorGraph::unselect() {
    m_label->setFont(QFont(m_graph->parentPlot()->font().family(), 8));
    m_label->setPen(QPen(Qt::black));

    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::red);
    m_graph->setPen(pen);
}
