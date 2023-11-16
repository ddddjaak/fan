#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "include_all.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QString data;
    ec_init();
    this->init_temp();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateTemp(void)
{
    unsigned char test = 0;
    test = EC_Read_Data(0x320);
    QString str_x = QString::number(test,10);
    ui->lineEdit_cpu_temp->setText(str_x);
    qDebug() << "我会定时执行";
}

void MainWindow::init_temp()
{
    QTimer *mytimer = new QTimer;
    qDebug() << "ssss";
    connect(mytimer,&QTimer::timeout,this,&MainWindow::UpdateTemp);
    qDebug() << "2222";
    mytimer->start(1000);

    qDebug() << "运行到这里了没";
}
