#include<iostream>
#include "myHeap.h"

int Heap::get_left_index(int index)
{
	return 2 * index + 1;
}

int Heap::get_right_index(int index)
{
	return 2 * index + 1;
}

int Heap::get_parent(int index)
{
	return (index - 1) / 2;
}

void Heap::shiftup(int i)//i为需要堆化的元素的index
{
	int s = i;
	
	while (true) {
		int p = get_parent(s);
		if (p < 0 || data[p] >= data[s])//为什么这个放下面就不行？？
			break;
		if (data[p] < data[s])//需要堆化
		{
			/*
			int temp= data[p];
			data[p] = data[s];
			data[s] = temp;
			*/
			swap(data[p], data[s]);
		}

		//向上走
		s = p;
		}
		
	return;

	while (true) {
		// 获取节点i 的父节点
		int p = get_parent(i);
		// 当“越过根节点”或“节点无须修复”时，结束堆化
		if (p < 0 || data[i] <= data[p])
			break;
		// 交换两节点
		swap(data[i], data[p]);
		// 循环向上堆化
		i = p;
	}
}

void Heap::push(int val)
{
	data.push_back(val);
	shiftup(data.size() - 1);

}

void Heap::pop(int val)
{
}

int Heap::peek()
{
	return data[0];
}

int Heap::size()
{
	return data.size();
}

int Heap::isEmpty()
{
	return data.empty();
}

vector<int> Heap::toVector()
{
	return data;
}
