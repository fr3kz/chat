#include "chatpage.h"
#include "ui_chatpage.h"


chatpage::chatpage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chatpage)
{
    ui->setupUi(this);
}

chatpage::~chatpage()
{
    delete ui;
}
