﻿#include "MainWindow.h"
#include "ZZConfigWidget/ZZConfigWidget.h"
#include <QBoxLayout>
#include <QPushButton>
#include <QSplitter>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("ZhuZhuaoGUI"));
    setMinimumSize(1000, 600);
    // 初始化界面
    if (false == InitWidget())
    {
        throw std::bad_alloc();
    }
}

MainWindow::~MainWindow() {}

// 初始化
bool MainWindow::InitWidget()
{
    m_pMainWidget = new QWidget(this);
    m_pLeftTopWidget = new QWidget(this);
    m_pLeftBottomWidget = new QWidget(this);
    m_pRightWidget = new QWidget(this);

    // 左布局
    auto *pLeftVSplitter = new QSplitter(Qt::Vertical, this);
    pLeftVSplitter->setContentsMargins(0, 0, 0, 0);

    // 左上角
    m_pLeftTopWidget->setMinimumSize(400, 300);

    auto *pLeftTopHLayout = new QHBoxLayout();
    pLeftTopHLayout->setContentsMargins(0, 0, 0, 0);
    pLeftTopHLayout->setSpacing(0);

    m_pConfigWidget = new ZZConfigWidget(this);
    pLeftTopHLayout->addWidget(m_pConfigWidget);

    m_pLeftTopWidget->setLayout(pLeftTopHLayout);

    // 左下角
    m_pLeftBottomWidget->setMinimumHeight(100);

    pLeftVSplitter->addWidget(m_pLeftTopWidget);
    pLeftVSplitter->addWidget(m_pLeftBottomWidget);

    // 右布局
    auto *pRightHLayout = new QHBoxLayout();
    pRightHLayout->setContentsMargins(0, 0, 0, 0);

    m_pRightWidget->setLayout(pRightHLayout);

    // 整体布局
    auto *pMainHSplitter = new QSplitter();
    pMainHSplitter->setOrientation(Qt::Horizontal);

    pMainHSplitter->addWidget(pLeftVSplitter);
    pMainHSplitter->addWidget(m_pRightWidget);

    auto *pMainHLayout = new QHBoxLayout();
    pMainHLayout->setContentsMargins(0, 0, 0, 0);
    pMainHLayout->addWidget(pMainHSplitter);

    m_pMainWidget->setLayout(pMainHLayout);

    this->setCentralWidget(m_pMainWidget);
    return true;
}
