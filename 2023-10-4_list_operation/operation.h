#pragma once
#include <iostream>
using namespace std;

//������
struct Node {
    char data;
    int rate=0;//��¼���ʴ���
    Node* next=nullptr;
    Node* prior=nullptr;
};
//�ඨ��
class operation
{
public:
    operation();
    ~operation();
    void locate(char x);//��λ����
    void InPut();//��ֵ���뺯��
    void OutPut();//�����ֵ����

private:
    Node* head = nullptr;
    int count = 0;
    void move_ahead(Node* cur);
    void swap_node(Node* A, Node* B);
};

