#ifndef CUSTOMIMAGEVIEW_H
#define CUSTOMIMAGEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>
class CustomImageViewItem;
class CustomImageView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CustomImageView(QWidget *parent = nullptr);
private:
    void InitWidget();
    void FitFrame();
    void OnCenter();
    void onZoom(double scale);
    void CreateTilePixmap();
protected:
    void wheelEvent(QWheelEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
private:
    QGraphicsScene* m_pScene{Q_NULLPTR}; // 场景
    CustomImageViewItem* m_pPixViewItem{Q_NULLPTR}; // 图像item
    QWidget* m_pImageInfoWidget{Q_NULLPTR}; // 左下角信息
    QLabel* m_pImageInfoLabel{Q_NULLPTR};

    // 展示图片
    QImage m_qImage;
    QPixmap m_Image;

    // 目前缩放的程序值
    double m_scaleValue{1.0};

    // 背景图片
    QPixmap m_tilePixmap{36,36};
public slots:
    void SetImage(const QImage& image);
signals:
};

#endif // CUSTOMIMAGEVIEW_H
