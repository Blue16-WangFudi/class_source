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

void Heap::shiftup(int i)//iΪ��Ҫ�ѻ���Ԫ�ص�index
{
	int s = i;
	
	while (true) {
		int p = get_parent(s);
		if (p < 0 || data[p] >= data[s])//Ϊʲô���������Ͳ��У���
			break;
		if (data[p] < data[s])//��Ҫ�ѻ�
		{
			/*
			int temp= data[p];
			data[p] = data[s];
			data[s] = temp;
			*/
			swap(data[p], data[s]);
		}

		//������
		s = p;
		}
		
	return;

	while (true) {
		// ��ȡ�ڵ�i �ĸ��ڵ�
		int p = get_parent(i);
		// ����Խ�����ڵ㡱�򡰽ڵ������޸���ʱ�������ѻ�
		if (p < 0 || data[i] <= data[p])
			break;
		// �������ڵ�
		swap(data[i], data[p]);
		// ѭ�����϶ѻ�
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
