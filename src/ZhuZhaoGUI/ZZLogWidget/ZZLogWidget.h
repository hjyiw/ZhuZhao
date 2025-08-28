#ifndef ZZLOGWIDGET_H
#define ZZLOGWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTextBrowser>

class ZZLogWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ZZLogWidget(QWidget *parent = nullptr);
private:
    void InitWindow();
    void InitContent();
private:
    QPushButton* m_pClearBtn{Q_NULLPTR};
    QTextBrowser* m_pLogTextBrowser{Q_NULLPTR};

signals:
};

#endif // ZZLOGWIDGET_H
