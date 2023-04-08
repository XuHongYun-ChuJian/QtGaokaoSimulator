
#ifndef COMMON_H
#define COMMON_H

#include <QtGlobal>
#include <QByteArray>
#include <QStringList>
#include "../ILog.h"

#define DELIMITERFUNC ":"
#define DELIMITERBODY ";"

namespace GaoKaoSimluator {

enum CmdCode{
    LogIn = 0x01,   //登录
};

//规定客户端和服务器之前的消息协议
//Function:Args;Args
//示例：0x01:用户名;密码 客户端发送的登录消息
//示例：0x01:200       登录成功

QString package(quint16 func , QStringList bodyList)
{
    QString msg;
    msg.append(func);
    msg.append(DELIMITERFUNC);

    for(const auto& body : bodyList)
    {
        msg.append(body);
        if( bodyList.last() != body)
        {
            msg.append(DELIMITERBODY);
        }
    }

    return msg;
}

QStringList unpackage(QByteArray &receiveMsg)
{
    QString msg = receiveMsg;
    QStringList funcList = msg.split(DELIMITERFUNC);
    if( funcList.isEmpty() )
    {
        LOG_WARN()<< "接收消息格式错误：" << msg;
        return QStringList();
    }

    QStringList bodyList = funcList.at(1).split(DELIMITERBODY);
}
}

#endif // COMMON_H
