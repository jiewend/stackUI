#include "imtoolitem.h"

ImToolItem::ImToolItem(QWidget *parent) : QWidget(parent)
{
    intiaView();
}


void ImToolItem::intiaView(){

    isShowList = false;
    btn = new QQButton(&title);
     btn->setMinimumHeight(40);

    connect(btn,SIGNAL(clicked()),this,SLOT(show_or_hide_list()));
    layout = new QVBoxLayout();
    layout->setContentsMargins(5,5,5,5);
    layout->setMargin(0);
    layout->addWidget(btn);


    layout->setSpacing(0);

    setLayout(layout);
    item_list = new QList<QWidget *>();

}

void ImToolItem::show_or_hide_list(){
    //item_list->at(0)->setVisible(true);
    for(int i = 0;i < item_list->size();i++){
        item_list->at(i)->setVisible(!(item_list->at(i)->isVisible()));
//        item_list->at(i)->setVisible(true);
        isShowList = item_list->at(i)->isVisible();
    }
}


ImToolItem::ImToolItem(QString title){
    this->title = title;
    intiaView();

}
void ImToolItem::addItem(QWidget *item){
     this->layout->addWidget(item);
    item->setMinimumHeight(50);
    //item->setMaximumHeight(40);
    item->setVisible(false);
    qDebug() << "This is function addItem()";
    item_list->append(item);

}

ImToolItem::~ImToolItem()
{

}

bool ImToolItem::GetIsShowList()
{
    return isShowList;
}

