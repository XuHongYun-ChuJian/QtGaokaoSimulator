#include "MainWidget.h"
#include <QApplication>
#include "quihelper.h"
#include "appinit.h"
#include "ILog.h"

int main(int argc, char *argv[])
{
    setOutput();
//    QUIHelper::initMain();
#if (QT_VERSION >= QT_VERSION_CHECK(5,12,0))
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
//    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
#endif
    QApplication a(argc, argv);

    AppInit::Instance()->start();

    QUIHelper::setFont();
//    QUIHelper::setCode();

    //加载样式表
#if 0
    QFile file(":/qss/blacksoft.css");
    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();
    }
#endif

    MainWidget w;
    w.show();
    return a.exec();
}
