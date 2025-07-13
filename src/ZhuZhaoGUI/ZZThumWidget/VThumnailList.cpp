#include "VThumnailList.h"
#include "LitImgItemWidget.h"
#include "../const/const.h"
#include <QScrollBar>
#include <QBoxLayout>
VThumnailList::VThumnailList(QWidget *parent)
    : QWidget{parent}
{
    InitWidget();
    InitContent();
}

void VThumnailList::InitWidget()
{
    m_pListWidget = new QListWidget(this);

    QVBoxLayout* pVMainLayout = new QVBoxLayout();
    pVMainLayout->setContentsMargins(0,0,0,0);
    pVMainLayout->setSpacing(0);

    pVMainLayout->addWidget(m_pListWidget);
    this->setLayout(pVMainLayout);

    auto* pHScrollBar = m_pListWidget->horizontalScrollBar();
    pHScrollBar->setStyleSheet(R"(
            QScrollBar{
                background:transparent;
                height:5px;
                margin:0px 0px 0px 0px;
            }
            QScrollBar::handle{
                background:rgba(223, 223, 225, 200);
                border:0px;
                border-radius:5px;
                margin:0px 0px 0px 0px;
            }
            QScrollBar::handle:hover{
                background:lightgray;
            }
            QScrollBar::handle:pressed{
                background:rgba(200, 200, 200, 255);
            }
            QScrollBar::sub-page{
                background:transparent;
            }
            QScrollBar::add-page{
                background:transparent;
            }
            QScrollBar::up-arrow{
                background:transparent;
            }
            QScrollBar::down-arrow{
                background:transparent;
            }
            QScrollBar::sub-line{
                background:transparent; height:0px;
            }
            QScrollBar::add-line{
                background:transparent; height:0px;
            }
    )");

    // 滑动条
    m_pListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_pListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);// 需要才有

    // 列表顺序
    m_pListWidget->setFlow(QListWidget::TopToBottom);

    // 视图模式
    m_pListWidget->setViewMode(QListWidget::ViewMode::ListMode);

    //单选模式
    m_pListWidget->setSelectionMode(QListView::SingleSelection);
    m_pListWidget->setFocusPolicy(Qt::NoFocus);
    m_pListWidget->setSelectionRectVisible(false);
    // 滚动条以像素单位滚动
    m_pListWidget->setVerticalScrollMode(QListView::ScrollPerPixel);
    // 禁止拖拽
    m_pListWidget->setDragEnabled(false);

    // 间隔
    m_pListWidget->setSpacing(4);
}

void VThumnailList::InitContent()
{
    // 双击图片
    connect(m_pListWidget,&QListWidget::itemDoubleClicked,this,&VThumnailList::SlotItemDoubleClicked);
}

void VThumnailList::AddImage(const QImage &img)
{
    auto* pImgitemWidget = new LitImgItemWidget(this);
    pImgitemWidget->SetImage(img);
    auto* pListWidgetItem = new QListWidgetItem();
    pListWidgetItem->setSizeHint(QSize(this->width()-IMAGE_ITEM_Margin_SIZE,this->width()-IMAGE_ITEM_Margin_SIZE));
    // 添加自定义item
    m_pListWidget->addItem(pListWidgetItem);
    m_pListWidget->setItemWidget(pListWidgetItem,pImgitemWidget);

    m_listImage.push_back(img);
}

// 添加图片
void VThumnailList::SlotAddImages(const QList<QImage>& imgs)
{
    m_listImage.clear();
    m_pListWidget->clear();
    for(const auto& img : imgs){
        AddImage(img);
    }
}

// 双击展示图片
void VThumnailList::SlotItemDoubleClicked(QListWidgetItem *item)
{

    LitImgItemWidget* pImgItemWidget = dynamic_cast<LitImgItemWidget*>(m_pListWidget->itemWidget(item));
    QImage img = pImgItemWidget->image();
    emit SigShowImg(img);
}
