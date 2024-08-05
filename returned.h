#ifndef RETURNED_H
#define RETURNED_H
#include "map"


#include <QDialog>

namespace Ui {
class returned;
}

class returned : public QDialog
{
    Q_OBJECT

public:
    explicit returned(QWidget *parent = nullptr);
    ~returned();

public slots:
    void RLoaded(std::map<QString, std::pair<std::pair<bool,int>, std::map<QString, int>>>* library);

private slots:
    void on_comboBox_2_textActivated(const QString &arg1);
    void on_comboBox_3_textActivated(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::returned *ui;
    std::map<QString, std::pair<std::pair<bool,int>, std::map<QString, int>>>* newlibrary;

};

#endif // RETURNED_H
