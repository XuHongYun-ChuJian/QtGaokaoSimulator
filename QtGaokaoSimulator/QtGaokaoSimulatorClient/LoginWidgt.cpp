#include "LoginWidgt.h"
#include "ui_loginwidgt.h"
#include "../Common.h"
#include <QMessageBox>

using namespace GaoKaoSimluator;
LoginWidgt::LoginWidgt(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::LoginWidgt)
{
    ui->setupUi(this);

    this->setModal(true);

    this->setWindowFlags(Qt::WindowStaysOnTopHint);
}

LoginWidgt::~LoginWidgt()
{
    delete ui;
}

void LoginWidgt::slotDealMgs(QByteArray msg)
{

}

void LoginWidgt::on_btn_Login_clicked()
{
    quint16 cmdCode = CmdCode::LogIn;
    QString usrName = ui->lineEdit_ID->text();
    QString passWd = ui->lineEdit_PW->text();
    if( usrName.isEmpty() || passWd.isEmpty() )
    {
        QMessageBox::warning(this , "错误" , "账户和密码不能为空！");
        return;
    }

    QString msg;
}

