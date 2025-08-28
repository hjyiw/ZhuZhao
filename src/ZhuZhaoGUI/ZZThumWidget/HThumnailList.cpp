#include "HThumnailList.h"
#include "LitImgItemWidget.h"
#include "../const/const.h"
#include <QBoxLayout>
HThumnailList::HThumnailList(QWidget *parent)
    : QWidget{parent}
{
    InitWindow();
    QList<QImage> listImg{QImage(),QImage(),QImage()};
    AddImages(listImg);
}

void HThumnailList::InitWindow()
{
    QVBoxLayout* pVMainLayout = new QVBoxLayout();
    pVMainLayout->setSpacing(0);
    pVMainLayout->setContentsMargins(0,0,0,0);

    m_pListWidget = new QListWidget(this);

    pVMainLayout->addWidget(m_pListWidget);

    this->setLayout(pVMainLayout);

    m_pListWidget->setStyleSheet(R"(
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
    m_pListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    m_pListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // 列表顺序
    m_pListWidget->setFlow(QListView::LeftToRight);

    // 视图模式
    m_pListWidget->setViewMode(QListWidget::ViewMode::ListMode);

    // 单选模式
    m_pListWidget->setSelectionMode(QListWidget::SelectionMode::SingleSelection);
    m_pListWidget->setFocusPolicy(Qt::NoFocus);
    m_pListWidget->setSelectionRectVisible(false);

    // 滚动条以像素单位滚动
    m_pListWidget->setVerticalScrollMode(QListView::ScrollPerPixel);

    // 禁止拖拽
    m_pListWidget->setDragEnabled(false);

    // 间隔
    m_pListWidget->setSpacing(4);
}

// 添加图片
void HThumnailList::AddImage(const QImage &image)
{
    auto* pImgItemWidget = new LitImgItemWidget();
    pImgItemWidget->SetImage(image);

    auto* pListWidgetItem = new QListWidgetItem();
    pListWidgetItem->setSizeHint(QSize(this->width()- IMAGE_ITEM_Margin_SIZE,this->height()-IMAGE_ITEM_Margin_SIZE));

    m_pListWidget->addItem(pListWidgetItem);

    m_pListWidget->setItemWidget(pListWidgetItem,pImgItemWidget);

    m_listImage.push_back(image);
}

void HThumnailList::AddImages(QList<QImage> imgs)
{
    for(auto& img : imgs){
        AddImage(img);
    }
}
