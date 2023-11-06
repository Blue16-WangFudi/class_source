#pragma once
#include<vector>
using namespace std;
class Graph_Matrix {
private:
	//设计类，先考虑需要存什么数据
	vector<int> vertices; // 顶点列表，元素代表“顶点值”，索引代表“顶点索引”
	vector<vector<int>> adjMat; // 邻接矩阵，行列索引对应“顶点索引”。先行后列(外层为行)
	//接下来设计功能，先做一个声明，然后按照顺序在cpp文件中实现
	//然后是构造和析构函数，这个一般都有
private:
	vector<vector<int>> delete_matrix(vector<vector<int>> matrix, int i, int j);
	vector<int> delete_vector(vector<int> vec, int index);
	vector<vector<int>> delete_vector(vector<vector<int>> vec, int index);//其实我想通过模板合在一起的
	//其实有一个vector.erase的方法，可以直接移除一个元素
public:
	Graph_Matrix();
	~Graph_Matrix();
	//常见操作：增删改查
	void addVertex(int val);//添加一个顶点
	void addEdge(int i, int j,float weight);//添加一条边，ij为索引，weight为权重

	void removeVertex(int index);//移除一个顶点
	void removeEdge(int i, int j);//移除一条边

	int size();//获取顶点数量
	void print();//打印矩阵

	
};

class Graph_List {
public:
	void hello();
};