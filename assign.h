#ifndef ASSIGN_H
#define ASSIGN_H
#include "QAbstractButton"
#include  "set"

#include <QDialog>

namespace Ui {
class Assign;
}

class Assign : public QDialog
{
    Q_OBJECT

public:
    explicit Assign(QWidget *parent = nullptr);
    ~Assign();

public slots:
    void Loaded(std::map<QString, std::pair<std::pair<bool,int>, std::map<QString, int>>>* library,std::set<QString> *users);

private slots:
    void on_pushButton_clicked();
    void onRadioButtonClicked(QAbstractButton *);



signals:
    void update_table(QString Sname,QString name,QString no);

private:
    Ui::Assign *ui;
    std::map<QString, std::pair<std::pair<bool,int>, std::map<QString, int>>>* newlibrary;
    std::set<QString>* newusers;
};

#endif // ASSIGN_H
