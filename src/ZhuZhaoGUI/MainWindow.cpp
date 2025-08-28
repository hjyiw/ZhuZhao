#include "MainWindow.h"
#include "ZZConfigWidget/ZZConfigWidget.h"
#include "ZZThumWidget/VThumnailList.h"
#include "ZZThumWidget/HThumnailList.h"
#include "ZZViewWidget/CustomImageViewWidget.h"
#include "ZZLogWidget/ZZLogWidget.h"
#include "ZZLogWidget/ZZLogMessage.h"

#include <QBoxLayout>
#include <QPushButton>
#include <QSplitter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("ZhuZhuaoGUI"));
    setMinimumSize(1100, 500);
    // 初始化界面
    if (false == InitWidget())
    {
        throw std::bad_alloc();
    }

    InitContent();
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

    QVBoxLayout* pVLogLayout = new QVBoxLayout();
    pVLogLayout->setContentsMargins(0,0,0,0);
    pVLogLayout->setSpacing(0);

    m_pLogWidget = new ZZLogWidget(this);

    pVLogLayout->addWidget(m_pLogWidget);

    m_pLeftBottomWidget->setLayout(pVLogLayout);

    pLeftVSplitter->addWidget(m_pLeftTopWidget);
    pLeftVSplitter->addWidget(m_pLeftBottomWidget);


    // 右布局
    auto *pRightHLayout = new QHBoxLayout();
    pRightHLayout->setContentsMargins(0, 0, 0, 0);

    // 垂直图片列表
    m_pVThumnailList = new VThumnailList(this);
    m_pVThumnailList->setFixedWidth(130);

    // 视图
    QVBoxLayout* pVViewLayout = new QVBoxLayout();
    pVViewLayout->setContentsMargins(0,0,0,0);
    pVViewLayout->setSpacing(0);

    m_pImageViewWidget = new CustomImageViewWidget(this);
    m_pHThumnailList = new HThumnailList(this);

    pVViewLayout->addWidget(m_pImageViewWidget,4);
    pVViewLayout->addWidget(m_pHThumnailList,1);

    pRightHLayout->addWidget(m_pVThumnailList,1);
    pRightHLayout->addLayout(pVViewLayout,2);

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

// 初始化内容
void MainWindow::InitContent()
{
    // 加载图片到垂直图片列表
    connect(m_pConfigWidget,&ZZConfigWidget::SigLoadImgs,m_pVThumnailList,&VThumnailList::SlotAddImages);
    m_pConfigWidget->SlotAddImgs();

    // 双击展示图片到视图
    connect(m_pVThumnailList,&VThumnailList::SigShowImg,m_pImageViewWidget,&CustomImageViewWidget::SlotShowImg);
}
