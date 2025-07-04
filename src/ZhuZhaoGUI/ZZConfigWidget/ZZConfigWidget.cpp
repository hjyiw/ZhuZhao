#include "ZZConfigWidget.h"
#include "ZZOneParameterWidget.h"
#include <QBoxLayout>

ZZConfigWidget::ZZConfigWidget(QWidget *parent)
    : QWidget{parent}
    , m_pTopWidget(Q_NULLPTR)
    , m_pCenterWidget(Q_NULLPTR)
    , m_pBottomWidget(Q_NULLPTR)
    , m_pTitleLabel(Q_NULLPTR)
    , m_pResetBtn(Q_NULLPTR)
    , m_pRunBtn(Q_NULLPTR)
{
    // this->setMinimumSize(400,300);
    initWidget();
}

// 初始化界面
void ZZConfigWidget::initWidget()
{
    const auto CreateOneParaWidget = [&](QString strParaName)-> ZZOneParameterWidget*{
        auto* pOneParaWidget = new ZZOneParameterWidget(strParaName,this);
        pOneParaWidget->setFixedHeight(60);
        return pOneParaWidget;
    };

    m_pTopWidget = new QWidget(this);
    m_pCenterWidget = new QWidget(this);
    m_pBottomWidget = new QWidget(this);
    m_pTitleLabel = new QLabel(this);
    m_pResetBtn = new QPushButton(this);
    m_pRunBtn = new QPushButton(this);

    QFont font("Microsoft Yahei",12);
    font.setBold(true);

    // 上布局
    auto* pTopHLayout = new QHBoxLayout(m_pTopWidget);
    pTopHLayout->setContentsMargins(0,0,0,0);
    pTopHLayout->setSpacing(0);

    m_pTitleLabel->setFont(font);
    m_pTitleLabel->setMinimumHeight(30);
    m_pTitleLabel->setText(tr("parameter configuration"));

    pTopHLayout->addWidget(m_pTitleLabel);
    pTopHLayout->addStretch();

    // 中布局
    auto* pCenterVLayout = new QVBoxLayout(m_pCenterWidget);
    pCenterVLayout->setContentsMargins(0,0,0,0);
    pCenterVLayout->setSpacing(3);

    // 创建参数窗口
    auto* pFirstParamWidget = CreateOneParaWidget(tr("FirstParam"));
    auto* pSecondParamWidget = CreateOneParaWidget(tr("SecondParam"));
    auto* pThirdParamWidget = CreateOneParaWidget(tr("ThirdParam"));
    auto* pFourthParamWidget = CreateOneParaWidget(tr("FourthParam"));

    pCenterVLayout->addWidget(pFirstParamWidget);
    pCenterVLayout->addWidget(pSecondParamWidget);
    pCenterVLayout->addWidget(pThirdParamWidget);
    pCenterVLayout->addWidget(pFourthParamWidget);



    // 下布局
    auto* pBottomHLayout = new QHBoxLayout(m_pBottomWidget);
    pBottomHLayout->setContentsMargins(0,0,0,0);
    pBottomHLayout->setSpacing(5);

    m_pResetBtn->setText(tr("reset"));
    m_pResetBtn->setFixedSize(60,30);

    m_pRunBtn->setText(tr("run"));
    m_pRunBtn->setFixedSize(60,30);

    pBottomHLayout->addStretch();
    pBottomHLayout->addWidget(m_pResetBtn);
    pBottomHLayout->addWidget(m_pRunBtn);


    // 主布局
    auto* pMainVLayout = new QVBoxLayout(this);
    pMainVLayout->setContentsMargins(0,0,0,0);
    pMainVLayout->setSpacing(0);

    pMainVLayout->addWidget(m_pTopWidget);
    pMainVLayout->addWidget(m_pCenterWidget);
    pMainVLayout->addWidget(m_pBottomWidget);




}
