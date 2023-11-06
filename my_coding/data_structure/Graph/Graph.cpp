// Graph.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//<>和""的区别：<>：系统内部""：用户自己的

//面向对象的编程，你没有个几年的编程经验你不懂其中的妙处。这个设计的确方便了很多。
#include <iostream>
#include "MyGraph.h"

int main()
{
	Graph_Matrix ob1;
	ob1.addVertex(4);
	ob1.addVertex(7);
	ob1.addVertex(9);
	ob1.addVertex(8);
	ob1.addVertex(2);
	ob1.addEdge(1,2,2);
	ob1.addEdge(3, 4, 5);
	ob1.print();
	//ob1.removeVertex(2);
	ob1.removeEdge(1, 2);
	ob1.print();
	Graph_List ob2;
	ob2.hello();
}

