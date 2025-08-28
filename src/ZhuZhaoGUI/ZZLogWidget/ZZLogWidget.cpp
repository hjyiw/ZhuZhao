#include "ZZLogWidget.h"
#include "ZZLogMessage.h"
#include <QBoxLayout>
ZZLogWidget::ZZLogWidget(QWidget *parent)
    : QWidget{parent}
{
    InitWindow();
    InitContent();
}

void ZZLogWidget::InitWindow()
{
    m_pClearBtn = new QPushButton(this);
    m_pClearBtn->setText(tr("Clear"));
    m_pClearBtn->setIconSize(QSize(24,24));
    m_pClearBtn->setIcon(QIcon(":/Resouce/icon/clear.png"));

    QHBoxLayout* pHBtnLayout = new QHBoxLayout();
    pHBtnLayout->setContentsMargins(0,0,0,0);
    pHBtnLayout->setSpacing(0);

    pHBtnLayout->addWidget(m_pClearBtn);
    pHBtnLayout->addStretch();

    m_pLogTextBrowser = new QTextBrowser(this);

    QVBoxLayout* pVMainLayout = new QVBoxLayout();
    pVMainLayout->setContentsMargins(0,0,0,0);
    pVMainLayout->setSpacing(0);

    pVMainLayout->addWidget(m_pLogTextBrowser);
    pVMainLayout->addLayout(pHBtnLayout);

    this->setLayout(pVMainLayout);

}

void ZZLogWidget::InitContent()
{
    ZZLogMessage& instance =  ZZLogMessage::instance();
    connect(&instance,&ZZLogMessage::SigDebugHtmlMsg,m_pLogTextBrowser,&QTextBrowser::append);
}
