#ifndef LOGINWIDGT_H
#define LOGINWIDGT_H

#include <QDialog>

namespace Ui {
class LoginWidgt;
}

class LoginWidgt : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWidgt(QDialog *parent = nullptr);
    ~LoginWidgt();

signals:
    void sendMsg(QByteArray msg);

public slots:
    void slotDealMgs(QByteArray msg);

private slots:
    void on_btn_Login_clicked();

private:
    void dealLogInMsg(QByteArray msg);

private:
    Ui::LoginWidgt *ui;
};

#endif // LOGINWIDGT_H
