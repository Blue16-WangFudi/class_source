#include<iostream>
#include<vector>
using namespace std;
class Heap {
private:
	//�õ���С���ѣ����ô󶥶���
	vector<int> minHeap;
	void siftUp(int s);
	void siftUp2(int s);
	void move_delete(int index);
public:
	Heap() {};
	Heap(vector<int> val) :minHeap(val) { cout << "�ɹ�����"<<endl; }
	void push(int val);
	int top();
	void pop();//����ǰ���һ������
	void pop2();//��׼��
	int get_left(int index);
	int get_right(int index);
	int get_parent(int index);
	vector<int> tovector();


};
