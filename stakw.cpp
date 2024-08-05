#include "stakw.h"
#include "ui_stakw.h"
#include <QStandardItemModel>

stakW::stakW(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::stakW)
{
    ui->setupUi(this);

}

stakW::~stakW()
{
    delete ui;
}


void stakW::SLoaded(std::map<QString, std::pair<std::pair<bool,int>, std::map<QString, int>>>* library){
    ui->stackedWidget->setCurrentIndex(0);
    this->newlibrary = library;
    QStandardItemModel* model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels({"Book Name", "Type"});
    for (const auto& entry : *newlibrary) {
        const QString& bookName = entry.first;
        const bool isTechnical = entry.second.first.first;

        // Create item for book name
        QStandardItem* bookNameItem = new QStandardItem(bookName);

        // Create item for book type
        QStandardItem* typeItem = new QStandardItem(isTechnical ? "Technical" : "Non-Technical");

        // Append the items to the model
        QList<QStandardItem*> rowItems;
        rowItems << bookNameItem << typeItem;
        model->appendRow(rowItems);
    }

    // Set the model for the QTableView
    ui->tableView->setModel(model);
}










void stakW::on_all_radioButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void stakW::on_tech_radioButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QStandardItemModel* model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels({"Book Name", "Type"});
    for (const auto& entry : *newlibrary) {
        const QString& bookName = entry.first;
        const bool isTechnical = entry.second.first.first;

        // Check if the book is technical
        if (isTechnical) {
            // Create item for book name
            QStandardItem* bookNameItem = new QStandardItem(bookName);

            // Create item for book type
            QStandardItem* typeItem = new QStandardItem("Technical");

            // Append the items to the model
            QList<QStandardItem*> rowItems;
            rowItems << bookNameItem << typeItem;
            model->appendRow(rowItems);
        }
    }

    // Set the model for the QTableView
    ui->tableView_2->setModel(model);
}


void stakW::on_nonT_radioButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
    QStandardItemModel* model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels({"Book Name", "Type"});
    for (const auto& entry : *newlibrary) {
        const QString& bookName = entry.first;
        const bool isTechnical = entry.second.first.first;

        // Check if the book is technical
        if (!isTechnical) {
            // Create item for book name
            QStandardItem* bookNameItem = new QStandardItem(bookName);

            // Create item for book type
            QStandardItem* typeItem = new QStandardItem("Non-Technical");

            // Append the items to the model
            QList<QStandardItem*> rowItems;
            rowItems << bookNameItem << typeItem;
            model->appendRow(rowItems);
        }
    }

    // Set the model for the QTableView
    ui->tableView_3->setModel(model);
}

