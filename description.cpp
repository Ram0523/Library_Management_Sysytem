#include "description.h"
#include "ui_description.h"

description::description(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::description)
{
    ui->setupUi(this);
    setWindowTitle("Description");
}

description::~description()
{
    delete ui;
}

// void description::DLoaded(std::map<QString, std::pair<int, std::map<QString, int>>>* library){
//     this->newlibrary = library;

//     int row = 0;



//     //ui->tableWidget->clearContents();
//     ui->tableWidget->setRowCount(15);
//     ui->tableWidget->setColumnCount(5);
//     ui->tableWidget->setColumnWidth(0,200);
//     ui->tableWidget->setColumnWidth(1,200);
//     ui->tableWidget->setColumnWidth(2,200);
//     ui->tableWidget->setColumnWidth(3,200);
//     ui->tableWidget->setColumnWidth(4,200);

//     // Set column headers
//     QStringList headers;
//     headers << "Subject" << "Number of Books" << "User Name" << "Books Assigned" << "Remaining Books";
//     ui->tableWidget->setHorizontalHeaderLabels(headers);
//     for ( auto& entry : *newlibrary) {
//         const QString& subject = entry.first;
//         auto& subjectInfo = entry.second;
//         int numberOfBooks = subjectInfo.first;
//         auto& userBooksMap = subjectInfo.second;
//         int remainingBooks = numberOfBooks;
//         for (auto& userEntry : userBooksMap) {
//             const QString& userName = userEntry.first;
//             int booksAssigned = userEntry.second;


//                 remainingBooks -= booksAssigned;

//             // Insert values into the table
//             ui->tableWidget->setItem(row, 0, new QTableWidgetItem(subject));
//             ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(numberOfBooks)));
//             ui->tableWidget->setItem(row, 2, new QTableWidgetItem(userName));
//             ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(booksAssigned)));
//             ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(remainingBooks)));

//             // Move to the next row
//             row++;
//         }
//     }

// }


//try
void description::DLoaded(std::map<QString, std::pair<std::pair<bool, int>, std::map<QString, int>>>* library) {
    this->newlibrary = library;

    int row = 0;

    //ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(15);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setColumnWidth(0, 200);
    ui->tableWidget->setColumnWidth(1, 200);
    ui->tableWidget->setColumnWidth(2, 200);
    ui->tableWidget->setColumnWidth(3, 200);
    ui->tableWidget->setColumnWidth(4, 200);

    // Set column headers
    QStringList headers;
    headers << "Subject" << "Number of Books" << "User Name" << "Books Assigned" << "Remaining Books";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    for (auto& entry : *newlibrary) {
        const QString& subject = entry.first;
        auto& subjectInfo = entry.second;
        bool isTechnical = subjectInfo.first.first;
        int numberOfBooks = subjectInfo.first.second;
        auto& userBooksMap = subjectInfo.second;
        int remainingBooks = numberOfBooks;

        for (auto& userEntry : userBooksMap) {
            const QString& userName = userEntry.first;
            int booksAssigned = userEntry.second;

            remainingBooks -= booksAssigned;

            // Insert values into the table
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(subject));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(numberOfBooks)));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(userName));
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(booksAssigned)));
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(remainingBooks)));

            // Move to the next row
            row++;
        }
    }
}

