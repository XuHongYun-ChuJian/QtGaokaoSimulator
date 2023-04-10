/**********************************************
* @projectName   QtGaokaoSimulator
* @brief         摘要
* @param         void
* @return        void
* @author
* @date          2023-04-04
**********************************************/

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QThread>
#include <QToolButton>
#include "NetConnection.h"

#include "LoginWidgt.h"
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void initLogin();

    void initForm();
    void initNavLeft();
    void initNavTop();
    void setStyle(QWidget *widget, int borderWidth = 3, QString borderColor = "#029FEA",
                  QString normalBgColor = "#292F38", QString selectBgColor = "#1D2025",
                  QString normalTextColor = "#54626F", QString selectTextColor = "#FDFDFD");

    void initSql();

private slots:
    void buttonClickedLeft();

private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();

    void on_btnQuery_clicked();

private:
    Ui::MainWidget *ui;

    NetConnection pNetConnection;
    QThread pThread;

    LoginWidgt *pLoginWidgt{nullptr};

    QList<int> pixCharLeft;
    QList<QPixmap> pixNormalLeft;
    QList<QPixmap> pixDarkLeft;
    QList<QToolButton *> tbtnLeft;

    QSqlDatabase pSql;
};
#endif // MAINWIDGET_H
