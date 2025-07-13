#ifndef CUSTOMIMAGEVIEWWIDGET_H
#define CUSTOMIMAGEVIEWWIDGET_H

#include <QWidget>
#include <QGraphicsView>

class CustomImageView;
class CustomImageViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CustomImageViewWidget(QWidget *parent = nullptr);

    void InitWidget();

private:
    CustomImageView* m_pImageView{Q_NULLPTR};
public slots:
    void SlotShowImg(const QImage& img);
signals:
};

#endif // CUSTOMIMAGEVIEWWIDGET_H
