#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setGeometry(x(), y(), 800, 600);

    readData();

    setup(ui->customPlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readData()
{
    QFile f("/home/ratuvog/input.txt");
    if (!f.open(QIODevice::ReadOnly))
        return;

    QTextStream stream(&f);
    int size = 0;
    stream >> size;
    for(int i = 0; i < size && !stream.atEnd(); i++)
    {
        double x, y;
        stream >> x >> y;
        data.first.push_back(x);
        data.second.push_back(y);
    }
}

void MainWindow::setup(QCustomPlot *customPlot)
{
  // create graph and assign data to it:
  customPlot->addGraph();
  customPlot->graph(0)->setData(data.first, data.second);
  // give the axes some labels:
  customPlot->xAxis->setLabel("distance, km");
  customPlot->yAxis->setLabel("power, dB");
  // set axes ranges, so we see all data:
  customPlot->xAxis->setRange(0, 100);
  customPlot->yAxis->setRange(0, -100);

  customPlot->xAxis2->setVisible(true);
  customPlot->xAxis2->setTickLabels(false);
  customPlot->yAxis2->setVisible(true);
  customPlot->yAxis2->setTickLabels(false);
  // make left and bottom axes always transfer their ranges to right and top axes:
  connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
  connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));
  // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
  customPlot->graph(0)->rescaleAxes();
  // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
  customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

