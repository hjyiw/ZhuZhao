#ifndef ZZCONFIGWIDGET_H
#define ZZCONFIGWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
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
private:
    void initWidget();
};
#endif // ZZCONFIGWIDGET_H
