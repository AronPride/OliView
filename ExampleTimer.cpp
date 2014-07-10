#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    count = 0;

    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(MyTimerSlot()));

    timer->start(500);
}

void MainWindow::MyTimerSlot()
{
    QString str;
    str = QString::number(count);
    ui->label->setText(str);
    count += 1;

    if (count > 10){
        timer->stop();
        return;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
