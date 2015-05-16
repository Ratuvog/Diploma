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
#include "cursorgraph.h"
#include "plot.h"

Frame::Frame(QWidget *parent, ReflectogramReaderInterface *reader)
    : QWidget(parent),
      ui(new Ui::Frame),
      m_selectedCursor(0)
{
    ui->setupUi(this);

    ui->table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->table->horizontalHeader()->setMaximumHeight(20);
    ui->table->hide();

    m_infoModel = new DomainModel;

    MenuDomainView *menu = new MenuDomainView(this);
    menu->setModel(m_infoModel);
    createMenu(menu);

    AbstractDomainView *info = new FirstInfoDomainView(this);
    info->setModel(m_infoModel);
    setFirstInfo(info);

    info = new SecondInfoDomainView(this);
    info->setModel(m_infoModel);
    setSecondInfo(info);

    info = new ThirdInfoDomainView(this);
    info->setModel(m_infoModel);
    setThirdInfo(info);

    readData(reader);
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
    delete m_infoModel;
}

void Frame::readData(ReflectogramReaderInterface *reader)
{
    while (reader->hasNext())
    {
        QPointF p = reader->nextPoint();
        m_reflectogram.addPoint(p.x(), p.y());
    }
    m_infoModel->setReflectogram(&m_reflectogram);
    m_infoModel->updateAll();
}

void Frame::setup(Plot *customPlot)
{
    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(m_reflectogram.keys(), m_reflectogram.values());

    customPlot->setup();

    QPen pen;
    pen.setWidth(1);
    pen.setColor(QColor(255,0,0));
    customPlot->graph(0)->setPen(pen);
    customPlot->graph(0)->rescaleAxes();

    for(int i = 0 ; i < 2; ++i) {
    CursorModel *cursorModel = new CursorModel(&m_reflectogram);
    connect(cursorModel, SIGNAL(updated()), SLOT(cursorUpdated()));

    // set same value to new cursor from current selected cursor
    if (m_selectedCursor)
        cursorModel->setX(m_selectedCursor->model()->x());

    CursorGraph *cursor = new CursorGraph(
        ui->plot->addGraph(),
        cursorModel,
        m_labelProvider.borrowNext()
    );

    m_cursors.append(cursor);
    selectCursor(cursor);
    }

    ui->plot->replot();

}

void Frame::oneClicked()
{

}

void Frame::twoClicked()
{

}

void Frame::threeClicked()
{

}

void Frame::fourClicked()
{

}

void Frame::fiveClicked()
{

}

void Frame::sixClicked()
{

}

void Frame::selectCursor(CursorGraph *cursor)
{
    if (m_selectedCursor)
        m_selectedCursor->unselect();

    cursor->select();

    m_selectedCursor = cursor;
    ui->plot->replot();
    cursorUpdated();
}

void Frame::enterClicked()
{
    if (!m_selectedCursor)
        return;

    int index = m_cursors.indexOf(m_selectedCursor);
    index--;
    index += m_cursors.count();
    index %= m_cursors.count();

    selectCursor(m_cursors[index]);
}

void Frame::escClicked()
{
    if (!m_selectedCursor)
        return;

    m_labelProvider.release(m_selectedCursor->labelText());

    m_cursors.removeAll(m_selectedCursor);
    delete m_selectedCursor;

    m_selectedCursor = 0;
    if (m_cursors.count())
        selectCursor(m_cursors.back());

    ui->plot->replot();
}

void Frame::leftClicked()
{
    ui->plot->scaleX(1.17);
    ui->plot->replot();
}

void Frame::rightClicked()
{
    ui->plot->scaleX(0.84);
    ui->plot->replot();
}

void Frame::upClicked()
{
    ui->plot->scaleY(0.84);
    ui->plot->replot();
}

void Frame::downClicked()
{
    ui->plot->scaleY(1.17);
    ui->plot->replot();
}

void Frame::scrollUp()
{
    if (!m_selectedCursor)
        return;

    m_selectedCursor->move(m_selectedCursor->moveStep());

    ui->plot->replot();
}

void Frame::scrollDown()
{
    if (!m_selectedCursor)
        return;

    m_selectedCursor->move(-m_selectedCursor->moveStep());

    ui->plot->replot();
}

void Frame::cursorUpdated()
{
    CursorModel *cursorA = 0, *cursorB = 0;
    if (m_cursors.count() > 0)
        cursorA = m_cursors[0]->model();
    if (m_cursors.count() > 1)
        cursorB = m_cursors[1]->model();

    m_infoModel->setCursorA(cursorA);
    m_infoModel->setCursorB(cursorB);
    m_infoModel->updateAll();
}

