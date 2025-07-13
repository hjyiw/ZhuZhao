#include "CustomImageViewWidget.h"
#include "./CustomImageView.h"
#include <QBoxLayout>

CustomImageViewWidget::CustomImageViewWidget(QWidget *parent)
    : QWidget{parent}
{
    InitWidget();
}

// 初始化
void CustomImageViewWidget::InitWidget()
{
    m_pImageView = new CustomImageView(this);

    QVBoxLayout* pVMainLayout = new QVBoxLayout();
    pVMainLayout->setContentsMargins(0,0,0,0);
    pVMainLayout->setSpacing(0);

    pVMainLayout->addWidget(m_pImageView);

    this->setLayout(pVMainLayout);

}

// 双击展示图片到视图
void CustomImageViewWidget::SlotShowImg(const QImage &img)
{
    m_pImageView->SetImage(img);
}
