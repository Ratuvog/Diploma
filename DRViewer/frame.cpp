#include "frame.h"
#include "ui_frame.h"
#include "qcustomplot.h"
#include "reader.h"
#include "views/menudomainview.h"
#include "models/heterogenitymodel.h"
#include "views/firstinfodomainview.h"
#include "views/secondinfodomainview.h"
#include "views/thirdinfodomainview.h"
#include <models/domainmodel.h>

Frame::Frame(QWidget *parent, ReaderInterface *reader)
    : QWidget(parent),
      ui(new Ui::Frame)
{
    ui->setupUi(this);

    ui->table->setModel(new HeterogenityModel());
    ui->table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->table->horizontalHeader()->setMaximumHeight(20);

    QAbstractItemModel *model = new DomainModel;

    MenuDomainView *menu = new MenuDomainView(this);
    menu->setModel(model);
    createMenu(menu);

    AbstractDomainView *info = new FirstInfoDomainView(this);
    info->setModel(model);
    setFirstInfo(info);

    info = new SecondInfoDomainView(this);
    info->setModel(model);
    setSecondInfo(info);

    info = new ThirdInfoDomainView(this);
    info->setModel(model);
    setThirdInfo(info);

    readData();
    setup(ui->plot);
}

void Frame::createMenu(MenuDomainView *menu)
{
    QWidget *current = ui->menu->currentWidget();
    ui->menu->removeWidget(current);
    current->deleteLater();

    ui->menu->addWidget(menu);
    connect(menu, SIGNAL(clickToOne()), this, SLOT(oneClicked()));
    connect(menu, SIGNAL(clickToTwo()), this, SLOT(twoClicked()));
    connect(menu, SIGNAL(clickToThree()), this, SLOT(threeClicked()));
    connect(menu, SIGNAL(clickToFour()), this, SLOT(fourClicked()));
    connect(menu, SIGNAL(clickToFive()), this, SLOT(fiveClicked()));
    connect(menu, SIGNAL(clickToSix()), this, SLOT(sixClicked()));
}

void Frame::setFirstInfo(QWidget *widget)
{
    ui->info1th->addWidget(widget);
}

void Frame::setSecondInfo(QWidget *widget)
{
    ui->info2th->addWidget(widget);
}

void Frame::setThirdInfo(QWidget *widget)
{
    ui->info3th->addWidget(widget);
}

Frame::~Frame()
{
    delete ui;
}

void Frame::readData()
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

void Frame::setup(QCustomPlot *customPlot)
{
  // create graph and assign data to it:
  customPlot->addGraph();
  customPlot->graph(0)->setData(data.first, data.second);

  QPen pen;
  pen.setWidth(1);
  pen.setColor(QColor(255,0,0));
  customPlot->graph(0)->setPen(pen);

  // give the axes some labels:
  customPlot->xAxis->setLabel("km");
  customPlot->yAxis->setLabel("dB");

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

