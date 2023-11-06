#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "stdio.h"
#include "stdlib.h"
void MainWindow::on_Output_list_Button_clicked()//输出保存的链表
{
    ui->Output_list->clearContents();
    //遍历链表所有节点
    Node* temp=head->next;
    /*方案一：用i辅助遍历
    for(int a=1;a<=i;a++)//i为节点个数
    {
        ui->Output_list->insertRow(a-1);
        ui->Output_list->setItem(a-1,0,new QTableWidgetItem(temp->data.name));
        ui->Output_list->setItem(a-1,1,new QTableWidgetItem(temp->data.age));
        ui->Output_list->setItem(a-1,2,new QTableWidgetItem(temp->data.hobby));
        //切换到下一个节点
        temp=temp->next;
    }
    //这里只是为了方便写的，一般不要用计数的方式，如果程序做大了中途修改了数据，i很可能有变化，为了安全起见，一般用的是iterator（本质是指针）判断是否正确
    */
    //方案二：用iterator的方法（更安全）
    int a=1;
    while(temp!=NULL)
    {
        ui->Output_list->insertRow(a-1);
        ui->Output_list->setItem(a-1,0,new QTableWidgetItem(temp->data.name));
        ui->Output_list->setItem(a-1,1,new QTableWidgetItem(temp->data.age));
        ui->Output_list->setItem(a-1,2,new QTableWidgetItem(temp->data.hobby));
        //切换到下一个节点
        a++;
        temp=temp->next;
    }
}
MainWindow::MainWindow(QWidget *parent)//主窗体的构造函数
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"年龄"<<"爱好");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //初始化第二个
    ui->Output_list->setColumnCount(3);
    ui->Output_list->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"年龄"<<"爱好");
    ui->Output_list->setEditTriggers(QAbstractItemView::NoEditTriggers);


    head=new Node;
    head->next=NULL;
    head->data={};

}

MainWindow::~MainWindow()//主窗体的析构函数
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()//添加成员
{
    ui->tableWidget->insertRow(i);
    int count=0;
    Node* temp=head;
    for(;count<i;count++){
        temp=temp->next;
    }
    //申请一个新的节点
    Node* store=new Node;
    //往节点中存入数据
    store->data.name=ui->lineEdit->text();
    store->data.age=ui->lineEdit_2->text();
    store->data.hobby=ui->lineEdit_3->text();

    ui->tableWidget->setItem(i,0,new QTableWidgetItem(store->data.name));
    ui->tableWidget->setItem(i,1,new QTableWidgetItem(store->data.age));
    ui->tableWidget->setItem(i,2,new QTableWidgetItem(store->data.hobby));

    //结点链接
    store->next=temp->next;//与头节点链接
    temp->next=store;

    ui->lineEdit->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_2->clear();

    //计数器
    i++;
}


void MainWindow::on_pushButton_2_clicked()//删除成员
{
    int order=ui->spinBox_3->value();

    int count=0;
    Node* temp=head;
    for(;count<order-1;count++){
        temp=temp->next;
    }
    temp->next=temp->next->next;

    ui->tableWidget->removeRow(order-1);


    ui->lineEdit->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_2->clear();
    i--;
}


void MainWindow::on_pushButton_3_clicked()//插入成员,这里有问题
{
    int order=ui->spinBox_3->value();//获取要插入第几行（order），没有减1

    ui->tableWidget->insertRow(order-1);

    int count=0;
    Node* temp=head;//temp存储了头节点的指针
    for(;count<order-1;count++){
        temp=temp->next;
    }
    Node* store=new Node;//store存储了新节点的数据，现在需要上一个节点指向该节点，同时让该节点指向下一个节点
    store->data.name=ui->lineEdit->text();
    store->data.age=ui->lineEdit_2->text();
    store->data.hobby=ui->lineEdit_3->text();
    //**更正：这里不是i而是order-1
    ui->tableWidget->setItem(order-1,0,new QTableWidgetItem(store->data.name));
    ui->tableWidget->setItem(order-1,1,new QTableWidgetItem(store->data.age));
    ui->tableWidget->setItem(order-1,2,new QTableWidgetItem(store->data.hobby));

    //结点链接
    store->next=temp->next;
    temp->next=store;


    ui->lineEdit->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_2->clear();

    i++;
}



void MainWindow::on_pushButton_4_clicked()//按姓名查找
{
//    QString value = ui->lineEdit->text();
//    for (int var = 0; var <= ui->tableWidget->columnCount(); ++var) {
//        auto item= ui->tableWidget->item(var,0);
//        if (item==NULL)
//            continue;
//        QString name =item ->text();
//        if (name== value){
//            ui->label->setText(QString::number(var+1));
//        }
//    }
    ui->lineEdit->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_2->clear();
}


void MainWindow::on_pushButton_5_clicked()//按位查找
{

//    int value1=ui->spinBox_2->value()-1;
//     ui->label_2->setText(Person[value1].name);
//      ui->label_3->setText(Person[value1].age);
//       ui->label_4->setText(Person[value1].hobby);
//      ui->lineEdit->clear();
//      ui->lineEdit_3->clear();
//      ui->lineEdit_2->clear();

}

