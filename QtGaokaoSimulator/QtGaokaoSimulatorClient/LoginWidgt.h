#ifndef LOGINWIDGT_H
#define LOGINWIDGT_H

#include <QWidget>

namespace Ui {
class LoginWidgt;
}

class LoginWidgt : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidgt(QWidget *parent = nullptr);
    ~LoginWidgt();

signals:
    void sendMsg(QByteArray msg);

private:
    Ui::LoginWidgt *ui;
};

#endif // LOGINWIDGT_H
