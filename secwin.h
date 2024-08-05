#ifndef SECWIN_H
#define SECWIN_H

#include <QDialog>

namespace Ui {
class secwin;
}

class secwin : public QDialog
{
    Q_OBJECT

public:
    explicit secwin(QWidget *parent = nullptr);
    ~secwin();

public slots:
    void secLoaded(std::map<QString, std::pair<std::pair<bool,int>, std::map<QString, int>>>* library);


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

signals:
    void book_data_insert(QString name,QString no,bool b);
    void book_data_delete(QString name,QString no,bool b);

private:
    Ui::secwin *ui;
    //std::map<QString,int> *newlibrary;
    std::map<QString, std::pair<std::pair<bool,int>, std::map<QString, int>>>* newlibrary;
};

#endif // SECWIN_H
