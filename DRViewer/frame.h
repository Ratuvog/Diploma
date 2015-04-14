#ifndef FRAME_H
#define FRAME_H

#include <QWidget>

namespace Ui {
    class Frame;
}

class QCustomPlot;
class ReaderInterface;
class MenuDomainView;

class Frame : public QWidget
{
    Q_OBJECT
public:
    Frame(QWidget *parent, ReaderInterface *reader);
    ~Frame();

    void readData();
    void setup(QCustomPlot *customPlot);

signals:

public slots:

private:
    void createMenu(MenuDomainView *menu);
    void setFirstInfo(QWidget *widget);
    void setSecondInfo(QWidget *widget);
    void setThirdInfo(QWidget *widget);

private:
    typedef QPair<QVector<double>, QVector<double> > Coords;
    Coords data;
    Ui::Frame *ui;
};

#endif // FRAME_H
