#include "MainWindow.h"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 设置应用程序样式代码
    QStyle* style = QStyleFactory::create("fusion");
    a.setStyle(style);

    MainWindow w;
    w.show();
    return a.exec();
}
