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
#include "NetConnection.h"

#include "LoginWidgt.h"

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

private:
    Ui::MainWidget *ui;

    NetConnection pNetConnection;
    QThread pThread;

    LoginWidgt *pLoginWidgt{nullptr};
};
#endif // MAINWIDGET_H
