#include "MainWidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    pNetConnection.moveToThread(&pThread);
    connect(&pThread , &QThread::started , &pNetConnection , &NetConnection::init);
    connect(&pThread, &QThread::finished , &pNetConnection , &NetConnection::stopTimer);
    pThread.start();

    QTimer::singleShot(1000 , this , [=](){
        pNetConnection.initConnection("127.0.0.1" , 6000);
    });
}

MainWidget::~MainWidget()
{
    pThread.exit();
    pThread.wait();
    delete ui;
}

void MainWidget::initLogin()
{
    pLoginWidgt = new LoginWidgt(this);
}

