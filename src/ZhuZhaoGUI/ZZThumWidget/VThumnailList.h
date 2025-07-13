#ifndef VTHUMNAILLIST_H
#define VTHUMNAILLIST_H

#include <QWidget>
#include <QListWidget>
#include <QList>
#include <QImage>
class VThumnailList : public QWidget
{
    Q_OBJECT
public:
    explicit VThumnailList(QWidget *parent = nullptr);
private:
    void InitWidget();
    void InitContent();

    void AddImage(const QImage& image);
private:
    QListWidget* m_pListWidget{Q_NULLPTR};
    QList<QImage> m_listImage; // 存图像
public slots:
    void SlotAddImages(const QList<QImage>& imgs);
private slots:
    void SlotItemDoubleClicked(QListWidgetItem *item);
signals:
    void SigShowImg(const QImage& Img);
};

#endif // VTHUMNAILLIST_H
