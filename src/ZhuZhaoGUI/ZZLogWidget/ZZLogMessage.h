#ifndef ZZLOGMESSAGE_H
#define ZZLOGMESSAGE_H

#include <QObject>
#include <QDebug>

#define QDEBUG(message)     qDebug()<<" [FUNCTION]: "<<__FUNCTION__<<" [LINE]: "<<__LINE__<<" [LOG]: " << message;
#define QWARNING(message)   qWarning()<<" [FUNCTION]: "<<__FUNCTION__<<" [LINE]: "<<__LINE__<<" [LOG]: " << message;
#define QCRITICAL(message)  qCritical()<<" [FUNCTION]: "<<__FUNCTION__<<" [LINE]: "<<__LINE__<<" [LOG]: " << message;
#define QFATAL(message)     qFatal()<<" [FUNCTION]: "<<__FUNCTION__<<" [LINE]: "<<__LINE__<<" [LOG]: " << message;

class ZZLogMessage : public QObject
{
    Q_OBJECT
public:
    ZZLogMessage(const ZZLogMessage& z) = delete;
    ZZLogMessage& operator =(const ZZLogMessage& z) = delete;
    static ZZLogMessage& instance();
    void InstallMessageHandler();
    void UninstallMessageHandler();
    QString LogName();
    QString LogPath();
private:
    explicit ZZLogMessage(QObject *parent = nullptr);
    ~ZZLogMessage();
signals:
    void SigDebugStrMsg(QString strMsg);
    void SigDebugHtmlMsg(QString htmlMsg);
};

#endif // ZZLOGMESSAGE_H
