#include "update1.h"
#include "ui_update1.h"

update1::update1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::update1)
{
    ui->setupUi(this);
}

update1::~update1()
{
    delete ui;
}
