#ifndef ILOG_H
#define ILOG_H

#include <QtGlobal>
#include <QDateTime>
#include <QDebug>
#include <QThread>

#define DT_FORMAT_YMDHMSZ "yyyy-MM-dd hh:mm:ss zzz"
#define CURRENT_DT QString("[%1]").arg(QDateTime::currentDateTime().toString(DT_FORMAT_YMDHMSZ))
#define CURRENT_TR QString("[%1]").arg(quintptr(QThread::currentThread()))

#define LOG_DEBUG() qDebug().noquote() <<  CURRENT_DT << CURRENT_TR << "[Debug]" << Q_FUNC_INFO
#define LOG_INFO() qInfo().noquote() <<  CURRENT_DT << CURRENT_TR << "[Info]" << Q_FUNC_INFO
#define LOG_WARN() qWarning().noquote() <<  CURRENT_DT << CURRENT_TR << "[Warn]" << Q_FUNC_INFO
#define LOG_CRIT() qCritical().noquote() <<  CURRENT_DT << CURRENT_TR << "[Crit]" << Q_FUNC_INFO

#endif // ILOG_H
