#ifndef UPDATE1_H
#define UPDATE1_H

#include <QDialog>

namespace Ui {
class update1;
}

class update1 : public QDialog
{
    Q_OBJECT

public:
    explicit update1(QWidget *parent = nullptr);
    ~update1();

private:
    Ui::update1 *ui;
};

#endif // UPDATE1_H
