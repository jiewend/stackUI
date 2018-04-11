#include "imtoolbox.h"
#include <QScrollArea>
#include <QSpacerItem>
ImToolBox::ImToolBox(QWidget *parent) : QWidget(parent)
{
   // spacer = new QSpacerItem(20,20,QSizePolicy::Minimum,QSizePolicy::MinimumExpanding);
    layout = new QVBoxLayout();
    layout->setContentsMargins(0,10,10,10);
    layout->setSpacing(0);
    layout->setMargin(0);
    //layout->setStretch();
   // layout->addStretch(0);
    setLayout(layout);
}


void ImToolBox::addItem(ImToolItem *item){
   // item->setStyleSheet("background:red");


    int count = layout->count();
    if (count > 1)
    {
        layout->removeItem(layout->itemAt(count - 1));
    }
    layout->addWidget(item);
    layout->addStretch();
  //  layout->addSpacerItem(spacer);
    //layout->addWidget(new QScrollArea);
    //layout->setStretchFactor(item,1);
}

void ImToolBox::addItem(QWidget *item){
   // item->setStyleSheet("background:red");
    layout->addWidget(item);
  //  layout->addSpacerItem(spacer);
    //layout->addWidget(new QScrollArea);
    //layout->setStretchFactor(item,1);
}
ImToolBox::~ImToolBox()
{

}

