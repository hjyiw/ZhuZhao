#include "MainWindow.h"
#include "ZZLogWidget/ZZLogMessage.h"

#include <QApplication>
#include <QStyleFactory>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 设置应用程序样式代码
    QStyle* style = QStyleFactory::create("fusion");
    a.setStyle(style);

    // 安装日志拦截器
    ZZLogMessage::instance().InstallMessageHandler();

    // 设置翻译器
    auto* pTranslator = new QTranslator();
    pTranslator->load(":/language_ch.qm");
    a.installTranslator(pTranslator);

    MainWindow w;
    w.show();
    return a.exec();
}
