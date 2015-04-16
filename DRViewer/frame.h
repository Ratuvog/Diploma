#ifndef FRAME_H
#define FRAME_H

#include <QWidget>

#include "qcustomplot.h"
class Reflectogram {
public:
    void addPoint(double x, double y) {
        m_x.push_back(x);
        m_y.push_back(y);
    }

    const QVector<double>& keys() const { return m_x; }
    const QVector<double>& values() const { return m_y; }

    double value(double x) const {
        for (int i = 0; i < m_x.size(); ++i) {
            if (x == m_x[i])
                return m_y[i];
        }
        return 0;
    }

private:
    QVector<double> m_x;
    QVector<double> m_y;
};

class Cursor {
public:
    Cursor(Reflectogram *refl) : m_x(0), m_refl(refl) {}
    double value() const { return m_refl->value(m_x); }

    void setX(double value) { m_x = value; }
    double x() const { return m_x; }

private:
    double m_x;
    Reflectogram *m_refl;
};

class CursorGraph {
public:
    CursorGraph(QCPGraph *graph, Cursor *c, const QString &label)
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

    ~CursorGraph() {
        m_graph->parentPlot()->removeItem(m_label);
        m_graph->parentPlot()->removeGraph(m_graph);
        delete m_cursor;
    }

    void updateGraph()
    {
        m_graph->clearData();
        m_graph->addData(m_cursor->x(), -65536);
        m_graph->addData(m_cursor->x(), 65536);
        m_label->position->setCoords(
            m_cursor->x(),
            m_graph->parentPlot()->yAxis->range().upper
        );
    }

    double moveStep() const {
        return m_graph->parentPlot()->xAxis->tickStep()/20.;
    }

    void move(double step) {
        m_cursor->setX(m_cursor->x() + step);
        updateGraph();
    }

    void select() {
        m_label->setFont(QFont(m_graph->parentPlot()->font().family(), 9));
        m_label->setPen(QPen(Qt::black));

        QPen pen;
        pen.setWidth(1);
        pen.setColor(Qt::green);
        m_graph->setPen(pen);
    }

    void unselect() {
        m_label->setFont(QFont(m_graph->parentPlot()->font().family(), 8));
        m_label->setPen(QPen(Qt::black));

        QPen pen;
        pen.setWidth(1);
        pen.setColor(Qt::red);
        m_graph->setPen(pen);
    }

    Cursor *model() const { return m_cursor; }
    QString labelText() const { return m_label->text(); }

private:
    QCPGraph *m_graph;
    QCPItemText *m_label;

    Cursor *m_cursor;
};

class LabelProvider
{
public:
    QString borrowNext() {
        for(int c = 'A'; c <= 'Z'; c++)
        {
            QString next = QString(QChar(c));
            if (!borrowed.contains(next))
            {
                borrowed.insert(next);
                return next;
            }
        }

        return QString();
    }

    void release(const QString &symbol) {
        borrowed.remove(symbol);
    }

private:
    QSet<QString> borrowed;
};


namespace Ui {
    class Frame;
}

class Plot;
class ReaderInterface;
class MenuDomainView;

class Frame : public QWidget
{
    Q_OBJECT
public:
    Frame(QWidget *parent, ReaderInterface *reader);
    ~Frame();

    void readData();
    void setup(Plot *customPlot);

signals:

public slots:
    void oneClicked();
    void twoClicked();
    void threeClicked();
    void fourClicked();
    void fiveClicked();
    void sixClicked();

    void enterClicked();
    void escClicked();

    void leftClicked();
    void rightClicked();

    void scrollUp();
    void scrollDown();

private:
    void createMenu(MenuDomainView *menu);

    void selectCursor(CursorGraph *cursor);

    void setFirstInfo(QWidget *widget);
    void setSecondInfo(QWidget *widget);
    void setThirdInfo(QWidget *widget);

private:
    Ui::Frame *ui;

    Reflectogram m_reflectogram;

    LabelProvider m_labelProvider;

    QList<CursorGraph*> m_cursors;
    CursorGraph *m_selectedCursor;
};

#endif // FRAME_H
