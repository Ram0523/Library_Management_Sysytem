#ifndef MAINWINDOW_H
#define MAINWINDOW_H
using namespace std;
#include <QMainWindow>
#include "secwin.h"
#include "description.h"
#include "assign.h"
#include "returned.h"
#include "stakw.h"
#include "set"
using UserInfoMap = std::map<QString, int>;
using SubjectMap = std::map<QString, std::pair<pair<bool,int>, UserInfoMap>>;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void add_books_map(){

        library["c++"] =    {{1,2}, {}};  // Initializing with an empty UserInfoMap
        library["python"] = {{1,5}, {}};
        library["linux"] =  {{1,4}, {}};
        library["novel1"]=  {{0,7},{}};
    }


    void add_users(){
        users.insert("ram");
        users.insert("tanmay");
        users.insert("amar");
    }


    void book_count()
    {
        count=0;
        for(auto  &it: library){
            count+=it.second.first.second;
        }
    }

    int ans(){
        return count;
    }

    void add_book();



private slots:
    void on_comboBox_textActivated(const QString &arg1);
    void update_insert(QString  name,QString no,bool b);
    void update_delete(QString  name,QString no,bool b);
    void on_pushButton_clicked();
    void update_insert_table(QString Sname,QString name,QString no);

    void on_actionGet_Details_triggered();

    void on_actionAssign_Book_triggered();



    void on_pushButton_2_clicked();

    void on_actionReturn_Books_triggered();

    void on_actionView_List_triggered();

private:
    Ui::MainWindow *ui;
    secwin * up;
    description * de;
    Assign * as;
    returned *re;
    stakW *st;


signals:
    void secondWindowloaded(map<QString, std::pair<pair<bool,int>, std::map<QString, int>>>* library);
    void Assignloaded(map<QString, std::pair<pair<bool,int>, std::map<QString, int>>>* library, set<QString> *users);

public:
    SubjectMap library;
    set<QString> users;
    int count;
};
#endif // MAINWINDOW_H
