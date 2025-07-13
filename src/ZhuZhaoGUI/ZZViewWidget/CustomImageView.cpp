#include "CustomImageView.h"
#include "./CustomImageViewItem.h"
#include "../../const/const.h"
#include <QLayout>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QDebug>

CustomImageView::CustomImageView(QWidget *parent)
    : QGraphicsView{parent}
{
    // View设置

    // 禁用滑动条
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // 反锯齿
    this->setRenderHint(QPainter::Antialiasing);

    // 设置变换锚点为视图中心，在进行缩放或旋转等变换时，保持视图中心不变
    this->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
    //解决拖动时背景图片残影
    // 设置视口更新模式为完整更新，每次绘制时都更新整个视口，这对动态内容效果更好但性能消耗更高
    this->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    // 开启手型平移拖动
    this->setDragMode(QGraphicsView::ScrollHandDrag);
    // 设置视图显示的场景部分 无限大
    this->setSceneRect(INT_MIN/2,INT_MIN/2,INT_MAX,INT_MAX);

    // 布局
    InitWidget();

    centerOn(0,0);
}

void CustomImageView::InitWidget()
{
    m_pScene = new QGraphicsScene(this);
    m_pPixViewItem = new CustomImageViewItem();

    // 设置场景
    this->setScene(m_pScene);
    m_pScene->addItem(m_pPixViewItem);

    m_pImageInfoWidget = new QWidget(this);
    m_pImageInfoLabel = new QLabel(this);
    m_pImageInfoLabel->setStyleSheet("color:rgb(200,255,200); "
                                   "background-color:rgba(50,50,50,160); "
                                   "font: Microsoft YaHei;"
                                   "font-size: 15px;");
    m_pImageInfoLabel->setText(" W:0,H:0 | X:0,Y:0 | R:0,G:0,B:0");


    QVBoxLayout* pVInfoLayout = new QVBoxLayout();
    pVInfoLayout->setContentsMargins(0,0,0,0);
    pVInfoLayout->setSpacing(0);

    pVInfoLayout->addWidget(m_pImageInfoLabel);

    m_pImageInfoWidget->setLayout(pVInfoLayout);

    // 放到左下角
    m_pImageInfoWidget->setGeometry(0,this->height()-30,this->width(),30);

    // 实时更新位置信息
    connect(m_pPixViewItem,&CustomImageViewItem::SigPosInfo,this,[=](auto strInfo){
        m_pImageInfoLabel->setText(strInfo);
    });

    // 准备背景图片
    CreateTilePixmap();
}

// 图片适应视图
void CustomImageView::FitFrame()
{
    if(this->width() < 1 || m_pPixViewItem->pixmap().width() < 1){
        return ;
    }

    auto winWidth = this->width();
    auto winHeight = this->height();
    qDebug() << "winWidth: " << winWidth;
    qDebug() << "winHeight: " << winHeight;
    qDebug() << "width: " << m_pPixViewItem->pixmap().width() + 1;
    qDebug() << "height: " << m_pPixViewItem->pixmap().height() + 1;
    // 先计算图片当前相对视图的宽高比
    // +1 防止图片铺满视图
    double widthScale = (m_pPixViewItem->pixmap().width() + 1) * 1.0 / winWidth;
    double heightScale = (m_pPixViewItem->pixmap().height() + 1) * 1.0 / winHeight;
    qDebug() << "widthScale:" << widthScale;
    qDebug() << "heightScale:" << heightScale;
    // 取比例高的 计算 视图是现在图片的多少倍
    auto tempScale =  widthScale >= heightScale ? widthScale / 1 : heightScale / 1;
    qDebug() << "tempScale: " << tempScale;
    // 计算还需缩放多少
    auto scale = tempScale / m_scaleValue;
    qDebug() << "scale: " << scale;
    // 缩放
    onZoom(scale);

    // 更新当前缩放程度
    m_scaleValue = tempScale;
}

// 图片居中
void CustomImageView::OnCenter()
{
    // 视图中心设为图片中心
    this->centerOn(m_pPixViewItem->pixmap().width() / 2,m_pPixViewItem->pixmap().height()/2);

    // 放置与视图对齐
    m_pPixViewItem->setPos(0,0);
}

// 放缩
void CustomImageView::onZoom(double scale)
{
    // 用于鼠标滚轮事件的缩放程度更新
    m_scaleValue = m_scaleValue * scale;

    this->scale(scale,scale);

}

// 准备一张背景图片
void CustomImageView::CreateTilePixmap()
{
    m_tilePixmap.fill(QColor(35, 35, 35));

    QPainter tilePainter(&m_tilePixmap);

    // 方格颜色
    const QColor color(50,50,50,255);

    // 在左上角和右下角绘制方格
    tilePainter.fillRect(0,0,18,18,color);
    tilePainter.fillRect(18,18,18,18,color);
}

// 鼠标滚轮事件
void CustomImageView::wheelEvent(QWheelEvent *event)
{
    auto angleDelta = event->angleDelta();

    auto y = angleDelta.y();

    // 放大倍数最多 50x
    if(y > 0  && m_scaleValue >= ZOOM_MAX){
        return ;
    }

    // 缩小倍数最多 50x
    if(y < 0 && m_scaleValue <= ZOOM_MIN){
        return ;
    }

    y > 0 ? onZoom(1.1) : onZoom(0.9);

    QGraphicsView::wheelEvent(event);
}

// 鼠标双击 图片自适应居中
void CustomImageView::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        FitFrame();
        OnCenter();
    }

    QGraphicsView::mouseDoubleClickEvent(event);

}

// 窗口大小改变事件
void CustomImageView::resizeEvent(QResizeEvent *event)
{
    // 图片自适应
    FitFrame();
    // 居中
    OnCenter();

    // 保持信息显示左下角
    m_pImageInfoWidget->setGeometry(0,height()-30,width(),30);

    QGraphicsView::resizeEvent(event);
}

// 绘制背景
void CustomImageView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this->viewport());
    painter.drawTiledPixmap(QRect(0,0,this->width(),this->height()),m_tilePixmap);

    QGraphicsView::paintEvent(event);
}

// 设置展示图片
void CustomImageView::SetImage(const QImage &image)
{
    m_qImage = image.copy();
    m_Image = QPixmap::fromImage(m_qImage);
    m_pPixViewItem->w = m_Image.width();
    m_pPixViewItem->h = m_Image.height();

    m_pPixViewItem->setPixmap(m_Image);

    // 图片适应视图
    FitFrame();

    // 居中
    OnCenter();

    show();

}


