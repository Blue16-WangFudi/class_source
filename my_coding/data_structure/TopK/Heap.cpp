#include<iostream>
#include"Heap.h"

void Heap::push(int val)
{
	//����minHeap
	minHeap.push_back(val);
	if (minHeap.size() == 1)
		return;
	//�ѻ�(����)
	siftUp(minHeap.size()-1);
}

int Heap::top()
{
	return minHeap[0];
}

void Heap::pop()
{
	//�����һ���㷨�����ڵ��ȥ���ӽڵ���������õݹ�
	move_delete(0);
	return;
}


int Heap::get_left(int index)
{
	return 2 * index + 1;
}

int Heap::get_right(int index)
{
	return 2 * index + 2;
}

int Heap::get_parent(int index)
{
	return (index - 1) / 2;
}

vector<int> Heap::tovector()
{
	return minHeap;
}

void Heap::siftUp(int s)
{
	while (true)
	{
		//��ȡ���ڵ��index
		int p = get_parent(s);
		//�ѻ����ʱ��
		if (minHeap[p] <= minHeap[s])
		{
			break;
		}

		//ΪʲôbreakҪ����ǰ�棿��Ϊswap��ǰԪ�ؾ�һ������break��������
		//��Ҫ�ѻ�
		if (minHeap[p] > minHeap[s])
		{
			swap(minHeap[p], minHeap[s]);
		}
		s = p;
	}
}

void Heap::siftUp2(int s)//��
{
	int i = s;
	while (true) {
		// ��ȡ�ڵ�i �ĸ��ڵ�
		int p = get_parent(i);
		// ����Խ�����ڵ㡱�򡰽ڵ������޸���ʱ�������ѻ�
		if (p < 0 || minHeap[i] >= minHeap[p])
			break;
		// �������ڵ�
		swap(minHeap[i], minHeap[p]);
		// ѭ�����϶ѻ�
		i = p;
	}
}

void Heap::move_delete(int index)
{
	if (index > (minHeap.size() - 1))
		return;
	int left = get_left(index);
	int right = get_right(index);
	//��Ҫ����һ���ж��Ƿ�Ҷ�ڵ������������������¶ѻ��㷨

	//���û���ˣ�left̫��
	if (left > (minHeap.size() - 1) && right<=(minHeap.size() - 1))
	{
		minHeap[index] = minHeap[right];
		minHeap[right] = minHeap[minHeap.size() - 1];
		minHeap.pop_back();
		return;
	}
	if (left <= (minHeap.size() - 1) && right > (minHeap.size() - 1))
	{
		minHeap[index] = minHeap[left];
		minHeap[left] = minHeap[minHeap.size() - 1];
		minHeap.pop_back();
		return;
	}
	if (left > (minHeap.size() - 1) && right > (minHeap.size() - 1))
	{
		return;
	}
	if (minHeap[left] <= minHeap[right])
	{
		swap(minHeap[left], minHeap[index]);
		move_delete(left);
	}
	else
	{
		swap(minHeap[right], minHeap[index]);
		move_delete(right);
	}
}
