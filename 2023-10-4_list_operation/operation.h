#pragma once
#include <iostream>
using namespace std;

//定义结点
struct Node {
    char data;
    int rate=0;//记录访问次数
    Node* next=nullptr;
    Node* prior=nullptr;
};
//类定义
class operation
{
public:
    operation();
    ~operation();
    void locate(char x);//定位函数
    void InPut();//数值输入函数
    void OutPut();//输出数值函数

private:
    Node* head = nullptr;
    int count = 0;
    void move_ahead(Node* cur);
    void swap_node(Node* A, Node* B);
};

