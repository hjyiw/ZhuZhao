#ifndef ZZCONFIGWIDGET_H
#define ZZCONFIGWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QList>
#include <QImage>

class ZZOneParameterWidget;
class ZZConfigWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ZZConfigWidget(QWidget *parent = nullptr);

private:
    QWidget* m_pTopWidget;
    QWidget* m_pCenterWidget;
    QWidget* m_pBottomWidget;

    QLabel* m_pTitleLabel;
    QPushButton* m_pResetBtn;
    QPushButton* m_pRunBtn;

    QList<ZZOneParameterWidget*> m_listParamWidget;
private:
    void InitWidget();
    void InitContent();

public slots:
    void SlotAddImgs();
signals:
    void SigLoadImgs(const QList<QImage>& imgs);
};
#endif // ZZCONFIGWIDGET_H
