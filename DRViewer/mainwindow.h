#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QCustomPlot;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void readData();
    void setup(QCustomPlot *customPlot);
private:
    Ui::MainWindow *ui;
    typedef QPair<QVector<double>, QVector<double> > Coords;
    Coords data;
};

#endif // MAINWINDOW_H
