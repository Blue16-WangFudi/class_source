#include<iostream>
#include <vector>
using namespace std;
class Heap {
private:
	//使用数组实现完美二叉树
	//做的是大顶堆
	vector<int> data;
	int get_left_index(int index);//获取左侧的index
	int get_right_index(int index);//获取右侧的index
	int get_parent(int index);//获取父节点的index
	void shiftup(int i);
public:
	void push(int val);
	void pop(int val);
	int peek();
	int size();
	int isEmpty();
	vector<int> toVector();
};
