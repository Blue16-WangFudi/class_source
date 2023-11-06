#include<iostream>
#include<vector>
using namespace std;
class Heap {
private:
	//用的是小顶堆，能用大顶堆吗？
	vector<int> minHeap;
	void siftUp(int s);
	void siftUp2(int s);
	void move_delete(int index);
public:
	Heap() {};
	Heap(vector<int> val) :minHeap(val) { cout << "成功构造"<<endl; }
	void push(int val);
	int top();
	void pop();//把最前面的一个弹出
	void pop2();//标准答案
	int get_left(int index);
	int get_right(int index);
	int get_parent(int index);
	vector<int> tovector();


};
