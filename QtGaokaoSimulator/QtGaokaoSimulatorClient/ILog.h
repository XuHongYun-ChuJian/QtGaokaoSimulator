#ifndef ILOG_H
#define ILOG_H

#include <QtGlobal>
#include <QDateTime>
#include <QDebug>
#include <QThread>

#define DT_FORMAT_YMDHMSZ "yyyy-MM-dd hh:mm:ss zzz"
#define CURRENT_DT QString("[%1]").arg(QDateTime::currentDateTime().toString(DT_FORMAT_YMDHMSZ))
#define CURRENT_TR QString("[%1]").arg(quintptr(QThread::currentThread()))

//#define LOG_DEBUG() qDebug().noquote()   <<  CURRENT_DT << CURRENT_TR << "[Debug]" << Q_FUNC_INFO
//#define LOG_INFO() qInfo().noquote()     <<  CURRENT_DT << CURRENT_TR << "[Info]" << Q_FUNC_INFO
//#define LOG_WARN() qWarning().noquote()  <<  CURRENT_DT << CURRENT_TR << "[Warn]" << Q_FUNC_INFO
//#define LOG_CRIT() qCritical().noquote() <<  CURRENT_DT << CURRENT_TR << "[Crit]" << Q_FUNC_INFO

#define LOG_DEBUG() qDebug()
#define LOG_INFO() qInfo()
#define LOG_WARN() qWarning()
#define LOG_CRIT() qCritical()

inline void outPutMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    const char *function = context.function ? context.function : "";
    QString typeInfo = "";
    switch (type) {
    case QtDebugMsg:
        typeInfo = "[Debug]";
        break;
    case QtInfoMsg:
        typeInfo = "[Info]";
        break;
    case QtWarningMsg:
        typeInfo = "[Warn]";
        break;
    case QtCriticalMsg:
        typeInfo = "[Crit]";
        break;
    case QtFatalMsg:
        typeInfo = "[Fatal]";
        break;
    }
    QString typeStr = QString("%1").arg(typeInfo , -7 , QChar(' '));
    fprintf(stderr, "%s [%u] %s %s:%u %s\n", CURRENT_DT.toLocal8Bit().constData(),
            quintptr(QThread::currentThread()),
            typeStr.toLocal8Bit().constData(),
            function ,
            context.line , localMsg.constData());
    //    fflush(stderr);
}

inline void setOutput()
{
    qInstallMessageHandler(outPutMessage);
    setbuf(stderr , NULL);
}

#endif // ILOG_H
