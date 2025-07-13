#ifndef CUSTOMIMAGEVIEWITEM_H
#define CUSTOMIMAGEVIEWITEM_H

#include <QGraphicsPixmapItem>
#include <QObject>
class CustomImageViewItem : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit CustomImageViewItem(QGraphicsItem *parent = nullptr);

public:
    int w;
    int h;
protected:
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;
signals:
    void SigPosInfo(const QString& strInfo);
};

#endif // CUSTOMIMAGEVIEWITEM_H
