#pragma once
#include <iostream>
#include <vector>
#include<queue>
using namespace std;

struct Node {
	char data;
	Node* left;
	Node* right;
	Node();
};
class operation
{private:
	Node* head;
	//������������������ȫ�ֲ��ܵ��ã���Ȼ�ᱻ�ͷš�
	//�����������Ҫ��ʼ����ʹ�ù��캯�����Ҽǵ���������ˡ�
	int count = 0;
public:
	operation();
	~operation();
	void Build();//������
	void PreInPut(Node* work,string msg);
	void Create_Tree();

	void Build_1();//ǰ��������
	void PreOrder(Node* work);
	Node* getRoot();

};

