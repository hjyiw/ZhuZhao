#include "LitImgItemWidget.h"
#include <QPainter>
LitImgItemWidget::LitImgItemWidget(QWidget *parent)
    : QWidget{parent}
{
    this->setFocusPolicy(Qt::StrongFocus);
}

void LitImgItemWidget::SetImage(QImage qImg)
{
    m_qImg = qImg;
}

const QImage &LitImgItemWidget::image()
{
    return m_qImg;
}

void LitImgItemWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    // 绘制图片
    QPainter painter(this);
    // 抗锯齿
    painter.setRenderHint(QPainter::Antialiasing);

    // 宽高
    int nWidth = this->width();
    int nHeight = this->height();

    // 没有图像就加载空图像
    if(m_qImg.isNull()){
        m_qImg = QImage(":/Resouce/icon/nullImg.png");
    }
    QPixmap tmpPixmap = QPixmap::fromImage(m_qImg);
    painter.drawPixmap(2,2,nWidth-5,nHeight-5,tmpPixmap);

    // 绘制边框
    QPen pen = painter.pen();
    pen.setColor(this->hasFocus() ? Qt::red : Qt::black);
    pen.setWidth(4);
    painter.setPen(pen);

    painter.drawRect(2,2,nWidth-5,nHeight-5);
    QWidget::paintEvent(event);
}
