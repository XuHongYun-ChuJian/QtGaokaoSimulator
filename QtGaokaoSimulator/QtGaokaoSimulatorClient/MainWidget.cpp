#include "MainWidget.h"
#include "ui_mainwidget.h"
#include "iconhelper.h"
#include "ILog.h"
#include <QSqlError>
#include <QFileDialog>
#include <QSqlQuery>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    initForm();
    initNavLeft();
    initNavTop();

    pNetConnection.moveToThread(&pThread);
    connect(&pThread , &QThread::started , &pNetConnection , &NetConnection::init);
    connect(&pThread, &QThread::finished , &pNetConnection , &NetConnection::stopTimer);
    pThread.start();

    QTimer::singleShot(1000 , this , [=](){
        pNetConnection.initConnection("127.0.0.1" , 6000);
    });

    initLogin();
    initSql();
}

MainWidget::~MainWidget()
{
    delete pLoginWidgt;

    pThread.exit();
    pThread.wait();
    delete ui;
}

void MainWidget::initLogin()
{
    pLoginWidgt = new LoginWidgt();
    pLoginWidgt->show();

    connect(pLoginWidgt , &LoginWidgt::sendMsg , &pNetConnection , &NetConnection::write);
    connect(&pNetConnection , &NetConnection::receiveData , pLoginWidgt , &LoginWidgt::slotDealMgs);
}

void MainWidget::initForm()
{
    this->setProperty("form", true);
    this->setProperty("canMove", true);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

    this->setWindowTitle("智能访客管理平台");

    IconHelper::Instance()->setIcon(ui->labTitle, QChar(0xf072), 35);
    IconHelper::Instance()->setIcon(ui->btnMenu_Min, QChar(0xf068));
    IconHelper::Instance()->setIcon(ui->btnMenu_Max, QChar(0xf067));
    IconHelper::Instance()->setIcon(ui->btnMenu_Close, QChar(0xf00d));

    ui->widgetNavLeft->setProperty("flag", "left");
    ui->widgetNavTop->setProperty("flag", "bottom");

    //应用样式
    QStringList qss;
    qss.append("QLabel#labTitle{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #2AA2DA, stop:1 #12B5C9);color:#F0F0F0;}");
    qss.append("QWidget#widgetTop{background:#FFFFFF;}");
    qss.append("QWidget#widgetMain{background:#F1F3F6;}");
    qss.append("QLabel#label{color:#202020;font:50pt;}");
    qss.append("QWidget#widgetNavLeft{background:#292F38;}");
    qss.append("QWidget[flag='left'] QToolButton{min-height:70px;max-height:70px;}");
    this->setStyleSheet(qss.join(""));
}

void MainWidget::initNavLeft()
{
    int borderWidth = 3;
    QString borderColor = "#029FEA";
    QString normalBgColor = "#292F38";
    QString selectBgColor = "#1D2025";
    QString normalTextColor = "#54626F";
    QString selectTextColor = "#FDFDFD";

    setStyle(ui->widgetNavLeft, borderWidth, borderColor, normalBgColor, selectBgColor, normalTextColor, selectTextColor);

    int size = 25;
    int pixWidth = 28;
    int pixHeight = 28;
    pixCharLeft << 0xf042 << 0xf045 << 0xf179 << 0xf056 << 0xf123 << 0xf099;
    tbtnLeft << ui->tbtn1 << ui->tbtn2 << ui->tbtn3 << ui->tbtn4 << ui->tbtn5 << ui->tbtn6;

    int count = tbtnLeft.count();
    for (int i = 0; i < count; i++) {
        pixNormalLeft.append(IconHelper::Instance()->getPixmap(normalTextColor, QChar(pixCharLeft.at(i)), size, pixWidth, pixHeight));
        pixDarkLeft.append(IconHelper::Instance()->getPixmap(selectTextColor, QChar(pixCharLeft.at(i)), size, pixWidth, pixHeight));
        tbtnLeft.at(i)->setIcon(QIcon(pixNormalLeft.at(i)));
        tbtnLeft.at(i)->setIconSize(QSize(size, size));
        tbtnLeft.at(i)->setCheckable(true);
        tbtnLeft.at(i)->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        connect(tbtnLeft.at(i), SIGNAL(clicked(bool)), this, SLOT(buttonClickedLeft()));
    }

    ui->tbtn1->click();
}

void MainWidget::initNavTop()
{
    int borderWidth = 5;
    QString borderColor = "#1CA0E4";
    QString normalBgColor = "#FFFFFF";
    QString selectBgColor = "#FAFBFD";
    QString normalTextColor = "#6D7173";
    QString selectTextColor = "#6D7173";

    setStyle(ui->widgetNavTop, borderWidth, borderColor, normalBgColor, selectBgColor, normalTextColor, selectTextColor);

    int size = 20;
    int pixWidth = 25;
    int pixHeight = 25;
}

void MainWidget::setStyle(QWidget *widget, int borderWidth, QString borderColor, QString normalBgColor, QString selectBgColor, QString normalTextColor, QString selectTextColor)
{
    QStringList qss;

    qss.append(QString("QWidget[flag=\"left\"] QAbstractButton{"
                       "border-style:none;"
                       "border-radius:0px;"
                       "padding:5px;"
                       "color:%1;"
                       "background:%2;}")
                   .arg(normalTextColor)
                   .arg(normalBgColor));

    qss.append(QString("QWidget[flag=\"left\"] QAbstractButton:hover,"
                       "QWidget[flag=\"left\"] QAbstractButton:pressed,"
                       "QWidget[flag=\"left\"] QAbstractButton:checked{"
                       "border-style:solid;"
                       "border-width:0px 0px 0px %1px;"
                       "padding:%2px %2px %2px %1px;"
                       "border-color:%3;"
                       "color:%4;"
                       "background:%5;}")
                   .arg(borderWidth)
                   .arg(borderWidth * 2)
                   .arg(borderColor)
                   .arg(selectTextColor)
                   .arg(selectBgColor));

    qss.append(QString("QWidget[flag=\"bottom\"] QAbstractButton{"
                       "border-style:none;"
                       "border-radius:0px;"
                       "padding:5px;"
                       "color:%1;"
                       "background:%2;}")
                   .arg(normalTextColor)
                   .arg(normalBgColor));

    qss.append(QString("QWidget[flag=\"bottom\"] QAbstractButton:hover,"
                       "QWidget[flag=\"bottom\"] QAbstractButton:pressed,"
                       "QWidget[flag=\"bottom\"] QAbstractButton:checked{"
                       "border-style:solid;"
                       "border-width:0px 0px %1px 0px;"
                       "padding:%2px %2px %1px %2px;"
                       "border-color:%3;"
                       "color:%4;"
                       "background:%5;}")
                   .arg(borderWidth)
                   .arg(borderWidth * 2)
                   .arg(borderColor)
                   .arg(selectTextColor)
                   .arg(selectBgColor));

    widget->setStyleSheet(qss.join(""));
}

void MainWidget::initSql()
{
    LOG_INFO()<< QSqlDatabase::drivers();
    QString sqlFile = QFileDialog::getOpenFileName(this , "" , ".");
    LOG_INFO()<< sqlFile;
    pSql = QSqlDatabase::addDatabase("QSQLITE");
    pSql.setHostName("127.0.0.1");
    pSql.setDatabaseName(sqlFile);
    pSql.setUserName("127.0.0.1");
    pSql.setPassword("123456");
    if( !pSql.open() )
    {
        LOG_WARN()<< "Open DataBase Faild." << pSql.lastError().text();
    }
    else
    {
        qInfo()<< "数据库连接成功.";
    }

    qInfo()<< "DataBase has tables:" << pSql.tables();

}

void MainWidget::buttonClickedLeft()
{
    QToolButton *b = (QToolButton *)sender();
    QString name = b->text();

    int count = tbtnLeft.count();
    for (int i = 0; i < count; i++) {
        if (tbtnLeft.at(i) == b) {
            tbtnLeft.at(i)->setIcon(QIcon(pixDarkLeft.at(i)));
            tbtnLeft.at(i)->setChecked(true);
        } else {
            tbtnLeft.at(i)->setIcon(QIcon(pixNormalLeft.at(i)));
            tbtnLeft.at(i)->setChecked(false);
        }
    }
}

void MainWidget::on_btnMenu_Min_clicked()
{
    showMinimized();
}

void MainWidget::on_btnMenu_Max_clicked()
{
    static bool max = false;
    static QRect location = this->geometry();

    if (max) {
        this->setGeometry(location);
    } else {
        location = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
    }

    this->setProperty("canMove", max);
    max = !max;
}

void MainWidget::on_btnMenu_Close_clicked()
{
    close();
}


void MainWidget::on_btnQuery_clicked()
{
    if( !pSql.isOpen() )
    {
        LOG_WARN()<< "DaseBase not Open.";
        return;
    }

    QSqlQuery query(pSql);
    query.exec("SELECT exam_number FROM student;");
    qDebug()<< query.lastError();
    while (query.next()) {
        int exam_number = query.value(0).toInt();
        qDebug() << "Exam Number:" << exam_number;
    }
}

