#include<iostream>
#include <vector>
using namespace std;
class Heap {
private:
	//ʹ������ʵ������������
	//�����Ǵ󶥶�
	vector<int> data;
	int get_left_index(int index);//��ȡ����index
	int get_right_index(int index);//��ȡ�Ҳ��index
	int get_parent(int index);//��ȡ���ڵ��index
	void shiftup(int i);
public:
	void push(int val);
	void pop(int val);
	int peek();
	int size();
	int isEmpty();
	vector<int> toVector();
};
