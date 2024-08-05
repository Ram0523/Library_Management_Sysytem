#include "returned.h"
#include "ui_returned.h"
#include "qdebug.h"
#include "qmessagebox.h"

returned::returned(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::returned)
{
    ui->setupUi(this);
    ui->comboBox_2->setPlaceholderText("Select");
    ui->comboBox_3->setPlaceholderText("Select");
}

returned::~returned()
{
    delete ui;
}

void returned::RLoaded(std::map<QString, std::pair<std::pair<bool,int>, std::map<QString, int>>>* library){
    this->newlibrary = library;
    for(auto &it:*newlibrary){
        ui->comboBox_2->addItem(it.first);
    }



}

void returned::on_comboBox_2_textActivated(const QString &arg1)
{
    ui->comboBox_3->clear();
    auto it=newlibrary->find(arg1);
    for(auto it2:it->second.second){
        ui->comboBox_3->addItem(it2.first);

    }
}






void returned::on_comboBox_3_textActivated(const QString &arg1)
{

    ui->textEdit->clear();
    QString sub = ui->comboBox_2->currentText();

    auto it = newlibrary->find(sub);
    if (it != newlibrary->end())
    {
        auto it2 = it->second.second.find(arg1);
        if (it2 != it->second.second.end())
        {
            ui->textEdit->setText(QString::number(it2->second));
        }
    }
}




void returned::on_pushButton_clicked()
{
    QString sub = ui->comboBox_2->currentText();
    QString user = ui->comboBox_3->currentText();
    int b_Assig=ui->textEdit->toPlainText().toInt();
    int b_Return= ui->textEdit_2->toPlainText().toInt();

    auto it=newlibrary->find(sub);
    if(b_Assig>=b_Return){
        it->second.second[user]-=b_Return;
        if(it->second.second[user]==0){
            it->second.second.erase(user);
            QMessageBox::information(this, "Success", "Book Returned Successfully");
        }
    }
    else{
        QMessageBox::information(this, "Warning", "Error in book return Quantity");
    }

}

