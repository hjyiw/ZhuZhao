#include "ZZLogMessage.h"

#include <QMutexLocker>
#include <QDateTime>
#include <QFile>
#include <QDir>
#include <QTextStream>


void LogMessageHandler(QtMsgType type, const QMessageLogContext & context, const QString & msg){
    Q_UNUSED(context);
    static QMutex mutex;
    QMutexLocker lock(&mutex);

    QString flagText;
    QString msgColor = "red";
    switch (type) {
        case QtDebugMsg:
            flagText = "[Debug]";
            msgColor = "darkgray";
            break;
        case QtInfoMsg:
            flagText = "[Info]";
            msgColor = "red";
            break;
        case QtWarningMsg:
            flagText = "[Warning]";
            msgColor = "darkorange";
            break;
        case QtFatalMsg:
            flagText = "[Fatal]";
            msgColor = "red";
            break;
        case QtCriticalMsg:
            flagText = "[Critical]";
            msgColor = "red";
            break;
        default:
            flagText = "[Default]";
            msgColor = "red";
            break;
    };

    ZZLogMessage& instance = ZZLogMessage::instance();

    QString strDate = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString strDateMsg = QString("[%1]").arg(strDate);

    QString strMessage = QString("%1%2%3").arg(flagText).arg(strDateMsg).arg(msg);

    QString htmlMessage = QString("<font color=%1>"+ strMessage + "</font>").arg(msgColor);

    emit instance.SigDebugStrMsg(strMessage);
    emit instance.SigDebugHtmlMsg(htmlMessage);

    // 写进日志文件
    auto filePath = instance.LogPath() + instance.LogName();
    QFile file(filePath);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Append)){
        return;
    }
    QTextStream write(&file);
    write.setCodec("UTF-8");

    write << strMessage << "\r\n";
    file.flush();
    file.close();

    if(file.size() < 1024*1024) return;

    for(int loop = 1;loop <= 4;loop ++){
        auto newName = QString("%1/%2_%3").arg(instance.LogPath()).arg(instance.LogName()).arg(loop);
        QFile newFile(newName);
        if(newFile.size() > 1024*1024) continue;
        else {
            file.rename(newName);
            return;
        }
    }

}



ZZLogMessage &ZZLogMessage::instance()
{
    static ZZLogMessage z;
    return z;
}

// 安装消息器
void ZZLogMessage::InstallMessageHandler()
{
    qInstallMessageHandler(LogMessageHandler);
}

// 卸载消息器
void ZZLogMessage::UninstallMessageHandler()
{
    qInstallMessageHandler(Q_NULLPTR);
}

// 日志名称
QString ZZLogMessage::LogName()
{
    return "log.txt";
}

// 日志路径
QString ZZLogMessage::LogPath()
{
    auto curDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    auto dirPath = QString("log/%1").arg(curDateTime);
    QDir dir(dirPath);
    if(!dir.exists()){
        dir.mkpath("./");
    }
    return dir.path() + "/";
}

ZZLogMessage::ZZLogMessage(QObject *parent)
    : QObject{parent}
{}

ZZLogMessage::~ZZLogMessage()
{

}
