#include "CustomImageViewItem.h"

#include <QGraphicsSceneHoverEvent>

CustomImageViewItem::CustomImageViewItem(QGraphicsItem *parent)
    : QGraphicsPixmapItem{parent}
{
    // 接受鼠标悬停事件
    setAcceptHoverEvents(true);
}

void CustomImageViewItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    auto mousePos = event->pos();
    int R,G,B;
    auto x = mousePos.x() < 0 ? 0 : mousePos.x();
    auto y = mousePos.y() < 0 ? 0 : mousePos.y();

    // 提取RGB
    pixmap().toImage().pixelColor(x,y).getRgb(&R,&G,&B);

    QString strInfo = QString(tr(" W:%1 H:%2 | X:%3 Y:%4 | R:%5 G:%6 B:%7")
                                  .arg(w).arg(h)
                                  .arg(x).arg(y)
                                  .arg(R).arg(G).arg(B));
    emit SigPosInfo(strInfo);
    QGraphicsPixmapItem::hoverMoveEvent(event);
}
