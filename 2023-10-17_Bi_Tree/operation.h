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
	//放在类中声明，这样全局才能调用，不然会被释放。
	//声明后如果需要初始化，使用构造函数。我记得你错两次了。
	int count = 0;
public:
	operation();
	~operation();
	void Build();//构造结点
	void PreInPut(Node* work,string msg);
	void Create_Tree();

	void Build_1();//前序遍历输出
	void PreOrder(Node* work);
	Node* getRoot();

};

