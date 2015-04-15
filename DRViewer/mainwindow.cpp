#include "frame.h"
#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

void MainWindow::setTransparent(QWidget *button)
{
    button->setAttribute(Qt::WA_TranslucentBackground);
    button->setStyleSheet("background: transparent;\noutline: 0;");
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    background(QPixmap(":/bg.png"))
{
    ui->setupUi(this);
    QSize windowSize(1100, 740);
    setMask(background.scaled(windowSize).mask());
    setMinimumSize(windowSize);

    setWindowFlags(Qt::FramelessWindowHint);

    setTransparent(ui->exitButton);
    setTransparent(ui->esc);
    setTransparent(ui->enter);
    setTransparent(ui->f1);
    setTransparent(ui->f2);
    setTransparent(ui->f3);
    setTransparent(ui->f4);
    setTransparent(ui->f5);
    setTransparent(ui->f6);
    setTransparent(ui->bf1);
    setTransparent(ui->bf2);
    setTransparent(ui->bf3);
    setTransparent(ui->bf4);
    setTransparent(ui->scroll);
    setTransparent(ui->left);
    setTransparent(ui->up);
    setTransparent(ui->right);
    setTransparent(ui->down);

    frame = new Frame(this, 0);
    connect(ui->f1, SIGNAL(clicked()), frame, SLOT(oneClicked()));
    connect(ui->f2, SIGNAL(clicked()), frame, SLOT(twoClicked()));
    connect(ui->f3, SIGNAL(clicked()), frame, SLOT(threeClicked()));
    connect(ui->f4, SIGNAL(clicked()), frame, SLOT(fourClicked()));
    connect(ui->f5, SIGNAL(clicked()), frame, SLOT(fiveClicked()));
    connect(ui->f6, SIGNAL(clicked()), frame, SLOT(sixClicked()));

    connect(ui->left, SIGNAL(clicked()), frame, SLOT(leftClicked()));
    connect(ui->right, SIGNAL(clicked()), frame, SLOT(rightClicked()));

    connect(ui->enter, SIGNAL(clicked()), frame, SLOT(enterClicked()));
    connect(ui->esc, SIGNAL(clicked()), frame, SLOT(escClicked()));

    connect(ui->scroll, SIGNAL(up()), frame, SLOT(scrollUp()));
    connect(ui->scroll, SIGNAL(down()), frame, SLOT(scrollDown()));

    ui->stackedWidget->addWidget(frame);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), background);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *o, QEvent *e)
{
    if (o == ui->scroll && e->type() == QEvent::Scroll)
    {
        frame->eventFilter(o, e);
        return true;
    }
    return QObject::eventFilter(o,e);
}
