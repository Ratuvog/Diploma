#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qpushbutton.h>

namespace Ui {
class MainWindow;
}

class QCustomPlot;
class Frame;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool initialize();
    void paintEvent(QPaintEvent *paintEvent);
    bool eventFilter(QObject *o, QEvent *e);

private:
    void setTransparent(QWidget *button);
    QString getFileName();

private:
    Ui::MainWindow *ui;
    QPixmap background;
    Frame *frame;
};

#endif // MAINWINDOW_H
