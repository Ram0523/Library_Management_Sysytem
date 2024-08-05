#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "update1.h"
#include "QDebug"
#include  "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    setWindowTitle("Library Management System");
    ui->comboBox->setPlaceholderText("select");

    MainWindow::add_books_map();
    MainWindow::add_book();
    MainWindow::add_users();
    MainWindow::book_count();
    ui->textEdit_2->setText(QString::number(ans()));
    emit SIGNAL(clicked(bool));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add_book(){
    for(auto &it:MainWindow::library){
        ui->comboBox->addItem(it.first);
    }
}


void MainWindow::on_comboBox_textActivated(const QString &arg1)
{
    QString res= QString ::number(MainWindow::library[arg1].first.second);
    ui->textEdit->setText(res);
}


void MainWindow::on_pushButton_clicked()
{
    up=new secwin(this);
    connect(this, &MainWindow::secondWindowloaded,up, &secwin::secLoaded);
    up->show();
    emit secondWindowloaded(&(this->library));
    connect(up,&secwin::book_data_insert,this,&MainWindow::update_insert);
    connect(up,&secwin::book_data_delete,this,&MainWindow::update_delete);
}

void MainWindow:: update_insert(QString  name,QString no,bool b){

    int n1=no.toInt();



    // Check if the subject is present in the library map
    auto it = library.find(name);
    if (it == library.end()) {
        library[name] = {{b,n1}, {}};
        ui->comboBox->addItem(name);
        QMessageBox::information(this, "Success", "Book Added ");
    } else {
        // If the subject is already present, update the existing value
        it->second.first.second += n1;  // Update the number_of_book_of_particular_subject
        QMessageBox::information(this, "Success", "Book Added ");
    }

    book_count();
    ui->textEdit_2->setText(QString::number(ans()));
}


void MainWindow::update_delete(QString name, QString no, bool b) {
    int n1 = no.toInt();
    if (library.find(name) == library.end()) {
        QMessageBox::information(this, "Warning", "Book not Available");
    } else {
        // If the name is already present, update the existing value
        auto& bookInfo = library[name].first;
        if (bookInfo.second >= n1) {
            bookInfo.second -= n1;  // Update the number_of_book_of_particular_subject

            // Check if the number of books is zero, and remove the entry if needed
            if (bookInfo.second <= 0) {
                library.erase(name);
                ui->comboBox->removeItem(ui->comboBox->findText(name));

            }
            QMessageBox::information(this, "Success", "Book Removed");
        } else {
            QMessageBox::information(this, "Warning", "Removing more than available book");
        }
    }

    book_count();
    ui->textEdit_2->setText(QString::number(ans()));
}



void MainWindow::on_actionGet_Details_triggered()
{
    de=new description(this);
     connect(this, &MainWindow::secondWindowloaded,de, &description::DLoaded);
    de->show();
    emit secondWindowloaded(&(this->library));
}


void MainWindow::on_actionAssign_Book_triggered()
{
    as=new Assign(this);
    connect(this, &MainWindow::Assignloaded,as, &Assign::Loaded);
    as->show();
    emit Assignloaded(&(this->library),&(this->users));
    connect(as,&Assign::update_table,this,&MainWindow::update_insert_table);

}



//try
void MainWindow::update_insert_table(QString Sname, QString name, QString no) {
    auto it = library.find(Sname);

    if (it != library.end()) {
        // The subject is found in the map
        auto& subjectInfo = it->second;
        qDebug()<<subjectInfo.second[name]+no.toInt();
        // Check if there are enough books available
        if (subjectInfo.first.second >= no.toInt()&& subjectInfo.second[name]+no.toInt()<= subjectInfo.first.second) {
            // Update user information for the given name
            subjectInfo.second[name] += no.toInt();
            QMessageBox::information(this, "Success", "Book Assigned ");
        } else {
            QMessageBox::information(this, "Warning", "Less Quantity Available");
        }
    }
}



void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit_4->clear();
    QString username = ui->textEdit_3->toPlainText();
    if(users.insert(username).second){
            ui->textEdit_4->setText("username added  successfully");
        }



}


void MainWindow::on_actionReturn_Books_triggered()
{
    re=new returned(this);
    connect(this, &MainWindow::secondWindowloaded,re, &returned::RLoaded);
    re->show();
    emit secondWindowloaded(&(this->library));
}




void MainWindow::on_actionView_List_triggered()
{
    st=new stakW(this);
    connect(this, &MainWindow::secondWindowloaded,st, &stakW::SLoaded);
    st->show();
    emit secondWindowloaded(&(this->library));
}

