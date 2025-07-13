#ifndef LITIMGITEMWIDGET_H
#define LITIMGITEMWIDGET_H

#include <QWidget>
#include <QImage>
class LitImgItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LitImgItemWidget(QWidget *parent = nullptr);

    void SetImage(QImage qImg);
    const QImage& image();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    QImage m_qImg;
signals:
};

#endif // LITIMGITEMWIDGET_H
