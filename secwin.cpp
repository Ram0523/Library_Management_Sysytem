#include "secwin.h"
#include "ui_secwin.h"
#include "mainwindow.h"

secwin::secwin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::secwin)
{
    ui->setupUi(this);
    setWindowTitle("Second window");
    ui->comboBox->setPlaceholderText("select");

}

void secwin::secLoaded(map<QString, std::pair<pair<bool,int>, std::map<QString, int>>>* library){
    this->newlibrary = library;
    for(auto &it:*newlibrary){
        ui->comboBox->addItem(it.first);
    }
}

secwin::~secwin()
{
    delete ui;
}



void secwin::on_pushButton_2_clicked()
{
    emit book_data_insert(ui->textEdit->toPlainText(),ui->textEdit_2->toPlainText(),ui->radioButton->isChecked() ? 1 : 0);

}


void secwin::on_pushButton_clicked()
{
    emit book_data_delete(ui->textEdit->toPlainText(),ui->textEdit_2->toPlainText(),ui->radioButton->isChecked() ? 1 : 0);
}

