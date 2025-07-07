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

    QImage GetImage() const;
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
    QImage m_imgSrc;

private:
    void InitWidget();
    void InitContent();
private slots:
    void SlotLoadImg();
signals:
    void SigLoadImg();
};

#endif // ZZONEPARAMETERWIDGET_H
