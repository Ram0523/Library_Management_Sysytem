#ifndef STAKW_H
#define STAKW_H

#include <QDialog>

namespace Ui {
class stakW;
}

class stakW : public QDialog
{
    Q_OBJECT

public:
    explicit stakW(QWidget *parent = nullptr);
    ~stakW();

public slots:
    void SLoaded(std::map<QString, std::pair<std::pair<bool,int>, std::map<QString, int>>>* library);

private slots:


    void on_all_radioButton_3_clicked();

    void on_tech_radioButton_2_clicked();

    void on_nonT_radioButton_clicked();


private:
    Ui::stakW *ui;
    std::map<QString, std::pair<std::pair<bool,int>, std::map<QString, int>>>* newlibrary;
};

#endif // STAKW_H
