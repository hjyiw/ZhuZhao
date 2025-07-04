#ifndef ZZONEPARAMETERWIDGET_H
#define ZZONEPARAMETERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QDoubleSpinBox>
class ZZOneParameterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ZZOneParameterWidget(const QString& title,QWidget *parent = nullptr);

    void setTitle(QString title);
private:
    QWidget* m_pTopWidget;
    QWidget* m_pBottomWidget;
    QLabel* m_pTitleLabel;
    QLabel* m_pSlantLabel;
    QLabel* m_pTiltLabel;
    QDoubleSpinBox* m_pSlantSpinBox;
    QDoubleSpinBox* m_pTiltSpinBox;
    QPushButton* m_pLoadBtn;
    QString m_strParamTitle;

private:
    void initWidget();
signals:
};

#endif // ZZONEPARAMETERWIDGET_H
