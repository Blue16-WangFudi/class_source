#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
#include <iostream>
using namespace Qt;
QT_END_NAMESPACE
//储存数据
typedef struct informantion
{
    QString name=0;
    QString hobby=0;
    QString age=0;
}Stu;
//定义结点
struct Node{
    Stu data;
    Node* next;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void OutPutList();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_Output_list_Button_clicked();

private:
    Ui::MainWindow *ui;
    Node* head;
    int i=0;
};

#endif // MAINWINDOW_H
