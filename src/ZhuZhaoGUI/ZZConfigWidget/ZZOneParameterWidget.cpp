#include "ZZOneParameterWidget.h"
#include <QBoxLayout>
ZZOneParameterWidget::ZZOneParameterWidget(const QString& title,QWidget *parent)
    : QWidget{parent}
    , m_pTopWidget(Q_NULLPTR),m_pBottomWidget(Q_NULLPTR)
    , m_pTitleLabel(Q_NULLPTR),m_pSlantLabel(Q_NULLPTR),m_pTiltLabel(Q_NULLPTR)
    , m_pSlantSpinBox(Q_NULLPTR),m_pTiltSpinBox(Q_NULLPTR)
    , m_pLoadBtn(Q_NULLPTR)
    , m_strParamTitle(title)
{
    this->setMinimumHeight(90);
    initWidget();
}

void ZZOneParameterWidget::setTitle(QString title)
{
    m_pTiltLabel->setText(tr(title.toLocal8Bit().constData()));
}

// 初始化界面
void ZZOneParameterWidget::initWidget()
{
    m_pTopWidget = new QWidget(this);
    m_pBottomWidget = new QWidget(this);
    m_pTitleLabel = new QLabel(this);
    m_pSlantLabel = new QLabel(this);
    m_pTiltLabel  = new QLabel(this);
    m_pSlantSpinBox = new QDoubleSpinBox(this);
    m_pTiltSpinBox = new QDoubleSpinBox(this);
    m_pLoadBtn = new QPushButton(this);

    QFont font("Microsoft Yahei",12);
    font.setBold(true);

    m_pTitleLabel->setFont(font);
    m_pTitleLabel->setText(m_strParamTitle);

    // 上布局
    auto* pTopVLayout = new QVBoxLayout(m_pTopWidget);
    pTopVLayout->setContentsMargins(0,0,0,0);
    pTopVLayout->setSpacing(0);

    pTopVLayout->addWidget(m_pTitleLabel);
    pTopVLayout->addStretch();

    // 下布局
    auto* pBottomHLayout = new QHBoxLayout(m_pBottomWidget);
    pBottomHLayout->setContentsMargins(0,0,0,0);
    pBottomHLayout->setSpacing(0);

    m_pSlantLabel->setText(tr("Slant:"));
    m_pTiltLabel->setText(tr("Tilt:"));

    m_pSlantSpinBox->setRange(-360,360);
    m_pTiltSpinBox->setRange(-360,360);

    m_pSlantSpinBox->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    m_pTiltSpinBox->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    m_pLoadBtn->setText(tr("load image"));

    pBottomHLayout->addWidget(m_pSlantLabel);
    pBottomHLayout->addWidget(m_pSlantSpinBox);
    pBottomHLayout->addWidget(m_pTiltLabel);
    pBottomHLayout->addWidget(m_pTiltSpinBox);
    pBottomHLayout->addWidget(m_pLoadBtn);

    // 主布局
    auto* pMainVLayout = new QVBoxLayout(this);
    pMainVLayout->setContentsMargins(0,0,0,0);
    pMainVLayout->setSpacing(0);

    pMainVLayout->addWidget(m_pTopWidget);
    pMainVLayout->addWidget(m_pBottomWidget);

}
