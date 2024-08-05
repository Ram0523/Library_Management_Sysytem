#include "assign.h"
#include "ui_assign.h"
#include "QAbstractButton"

Assign::Assign(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Assign)
{
    ui->setupUi(this);
    setWindowTitle("Assign Books");
    ui->comboBox->setPlaceholderText("select");
    ui->comboBox_2->setPlaceholderText("select");
    //connect(ui->radioButtonGroup,SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(onRadioButtonClicked(QAbstractButton *)));
}

Assign::~Assign()
{
    delete ui;
}


void Assign::Loaded(std::map<QString, std::pair<std::pair<bool,int>, std::map<QString, int>>>* library,std::set<QString> *users){
    this->newlibrary = library;
    this->newusers= users;

    for(auto &it:*newlibrary){
        ui->comboBox->addItem(it.first);
    }

    for(auto  &it:*newusers){
        ui->comboBox_2->addItem(it);
    }
}


void Assign::on_pushButton_clicked()
{
    emit update_table(ui->comboBox->currentText(),ui->comboBox_2->currentText(),ui->textEdit->toPlainText());
}

void Assign:: onRadioButtonClicked(QAbstractButton *button){
    if (button->isChecked()) {
         ui->comboBox->clear();  // Clear existing items
        // Do your specific task here

         if (button == ui->radioButton) {

            // Code for radioButton
            for (const auto &it : *newlibrary) {
                const QString &subject = it.first;
                const auto &subjectInfo = it.second;
                bool isTechnical = subjectInfo.first.first;

                if (isTechnical) {
                    ui->comboBox->addItem(subject);
                }
            }

         } else if (button == ui->radioButton_2) {
            // Code for radioButton_2

            for (const auto &it : *newlibrary) {
                const QString &subject = it.first;
                const auto &subjectInfo = it.second;
                bool isTechnical = subjectInfo.first.first;

                if (!isTechnical) {
                    ui->comboBox->addItem(subject);
                }
            }

         } else if (button == ui->radioButton_3) {
            // Code for radioButton_3
            for(auto &it:*newlibrary){
                ui->comboBox->addItem(it.first);
            }
        }
    }
}

