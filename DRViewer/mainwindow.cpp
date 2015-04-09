#include "frame.h"
#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

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

    ui->exitButton->setAttribute(Qt::WA_TranslucentBackground);
    ui->exitButton->setStyleSheet("background: transparent;\noutline: 0;");

    ui->stackedWidget->addWidget(new Frame(this));
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

