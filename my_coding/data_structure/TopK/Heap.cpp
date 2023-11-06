#include<iostream>
#include"Heap.h"

void Heap::push(int val)
{
	//加入minHeap
	minHeap.push_back(val);
	if (minHeap.size() == 1)
		return;
	//堆化(向上)
	siftUp(minHeap.size()-1);
}

int Heap::top()
{
	return minHeap[0];
}

void Heap::pop()
{
	//我想的一个算法：父节点出去后子节点来填，可以用递归
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
		//获取父节点的index
		int p = get_parent(s);
		//堆化完成时：
		if (minHeap[p] <= minHeap[s])
		{
			break;
		}

		//为什么break要放在前面？因为swap后当前元素就一定满足break的条件了
		//需要堆化
		if (minHeap[p] > minHeap[s])
		{
			swap(minHeap[p], minHeap[s]);
		}
		s = p;
	}
}

void Heap::siftUp2(int s)//答案
{
	int i = s;
	while (true) {
		// 获取节点i 的父节点
		int p = get_parent(i);
		// 当“越过根节点”或“节点无须修复”时，结束堆化
		if (p < 0 || minHeap[i] >= minHeap[p])
			break;
		// 交换两节点
		swap(minHeap[i], minHeap[p]);
		// 循环向上堆化
		i = p;
	}
}

void Heap::move_delete(int index)
{
	if (index > (minHeap.size() - 1))
		return;
	int left = get_left(index);
	int right = get_right(index);
	//需要加入一个判断是否到叶节点的条件！！这个是向下堆化算法

	//左侧没有了，left太大
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
