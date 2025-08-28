QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    ZZConfigWidget/ZZConfigWidget.cpp \
    ZZConfigWidget/ZZOneParameterWidget.cpp \
    ZZLogWidget/ZZLogMessage.cpp \
    ZZLogWidget/ZZLogWidget.cpp \
    ZZThumWidget/HThumnailList.cpp \
    ZZThumWidget/LitImgItemWidget.cpp \
    ZZThumWidget/VThumnailList.cpp \
    ZZViewWidget/CustomImageView.cpp \
    ZZViewWidget/CustomImageViewItem.cpp \
    ZZViewWidget/CustomImageViewWidget.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.h \
    ZZConfigWidget/ZZConfigWidget.h \
    ZZConfigWidget/ZZOneParameterWidget.h \
    ZZLogWidget/ZZLogMessage.h \
    ZZLogWidget/ZZLogWidget.h \
    ZZThumWidget/HThumnailList.h \
    ZZThumWidget/LitImgItemWidget.h \
    ZZThumWidget/VThumnailList.h \
    ZZViewWidget/CustomImageView.h \
    ZZViewWidget/CustomImageViewItem.h \
    ZZViewWidget/CustomImageViewWidget.h \
    const/const.h

RESOURCES += \
    ZhuZhaoGUIResource.qrc
#配置生成路径，将我们的结果输出产物输出到bin文件夹内，方便管理
CONFIG(debug, debug|release){
    DESTDIR = $$PWD/../bin
}else{
    DESTDIR = $$PWD/../bin
}
# 设置图标
RC_ICONS = zhuzhao_logo.ico

# 翻译文件
TRANSLATIONS += language_ch.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

