#ifndef HTHUMNAILLIST_H
#define HTHUMNAILLIST_H

#include <QWidget>
#include <QListWidget>
#include <QList>

class HThumnailList : public QWidget
{
    Q_OBJECT
public:
    explicit HThumnailList(QWidget *parent = nullptr);
private:
    void InitWindow();
    void AddImage(const QImage& image);
private:
    QListWidget* m_pListWidget{Q_NULLPTR};
    QList<QImage> m_listImage;
public slots:
    void AddImages(QList<QImage> imgs);
signals:
};

#endif // HTHUMNAILLIST_H
