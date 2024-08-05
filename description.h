#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include <QDialog>

namespace Ui {
class description;
}

class description : public QDialog
{
    Q_OBJECT

public:
    explicit description(QWidget *parent = nullptr);
    ~description();

public slots:
    void DLoaded(std::map<QString, std::pair<std::pair<bool,int>, std::map<QString, int>>>* library);

private:
    Ui::description *ui;
    std::map<QString, std::pair<std::pair<bool,int>, std::map<QString, int>>>* newlibrary;
};

#endif // DESCRIPTION_H
