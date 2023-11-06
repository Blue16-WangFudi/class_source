#include "MyGraph.h"//���߱����������cpp�еĴ�����MyGraph������ʵ��
#include <iostream>
using namespace std;

vector<vector<int>> Graph_Matrix::delete_matrix(vector<vector<int>> matrix, int i, int j)
{
	//һ��һ�е�ɾ��
	int count = 0;
	/*�������ò��ˣ��úú�������
	for (vector<vector<int>>::iterator it=matrix.begin();it!=matrix.end();it++)
	{
		if (count == i)
		{
			matrix=delete_vector(matrix, i);
			continue;
		}
		//delete_vector
		*it=delete_vector(*it, j);
		//it->ÿһ�е�ָ��*it->ÿһ��vector<int>
		count++;
	}
	*/
	int del = 0;
	//����д���õ�������
	/*���̫��ûд�������Ҿ��ÿ��Ի��㷨��
	for (int count = 0; count<matrix.size() ; count++)
	{
		cout << "������" << count << "��" << endl;
		if (count == i && del==0)
		{
			cout << "ɾ����" << count << "��" << endl;
			matrix = delete_vector(matrix, i);
			count--;
			del = 1;
			continue;
		}
		cout << "ɾ����" << j << "Ԫ��" << endl;
		vector<int> k=delete_vector(matrix[count], j);
		matrix[count] = k;
		//cout << "@---------" << endl;
		print();
	}
	*/
	//��ɾ����
	for (int a = 0; a < matrix.size(); a++)
	{
		if (a == i)
		{
			matrix = delete_vector(matrix, i);
			break;
		}
	}
	//Ȼ��ɾ����
	for (int a = 0; a < matrix.size(); a++)
	{
		matrix[a] = delete_vector(matrix[a], j);
	}


	return matrix;
}

vector<int> Graph_Matrix::delete_vector(vector<int> vec, int index)
{
	for (int i = index; i <= vec.size() - 2; i++)
	{
		vec[i] = vec[i + 1];
	}
	vec.pop_back();
	return vec;
}
vector<vector<int>> Graph_Matrix::delete_vector(vector<vector<int>> vec, int index)
{
	for (int i = index; i <= vec.size() - 2; i++)
	{
		vec[i] = vec[i + 1];
	}
	vec.pop_back();
	return vec;
}
Graph_Matrix::Graph_Matrix()
{
	/*
	cout << "delete vector test" << endl;
	vector<int> test;
	test.push_back(1);
	test.push_back(5);
	test.push_back(3);
	for (auto i : test)
	{
		cout << i << "\t";
	}

	vector<int> ret;
	ret = delete_vector(test, 0);
	cout << endl;
	for (auto i : ret)
	{
		cout << i << "\t";
	}

	cout << endl;
	*/
	
}

Graph_Matrix::~Graph_Matrix()
{

}

void Graph_Matrix::addVertex(int val)
{
	//���һ������
	vertices.push_back(val);
	//���ж��Ƿ�Ϊ�״���ӣ��״�Ϊ�գ�
	vector<int> temp;
	//vertices.push_back(val);
	if (adjMat.empty())
	{
		temp.push_back(0);
		adjMat.push_back(temp);
		//temp = adjMat[adjMat.size() - 1];
		//return;
	}
	else
	{
		//temp.clear();
		for (int i = 0; i < adjMat.size(); i++)//ȡ��ÿһ��
		{
			adjMat[i].push_back(0);
		}
		//��Ҫ���һ��
		vector<int> tmp(vertices.size(), 0);
		adjMat.push_back(tmp);
		//temp = adjMat[adjMat.size() - 1];
		//adjMat.push_back(temp);
	}

}

void Graph_Matrix::addEdge(int i, int j,float weight)
{
	//���һ���ߣ���Ҫ�������ط�

	if (i > (adjMat.size() - 1) || j > (adjMat[0].size() - 1))
	{
		cout << "Err : Index out of range." << endl;
		return;
	}
		
	adjMat[i][j] = weight;
	adjMat[j][i] = weight;
}

void Graph_Matrix::removeVertex(int index)
{
	adjMat=delete_matrix(adjMat, index, index);

}

void Graph_Matrix::removeEdge(int i, int j)
{
	if (i > (adjMat.size() - 1) || j > (adjMat[0].size() - 1))
	{
		cout << "Err : Index out of range." << endl;
		return;
	}

	adjMat[i][j] = 0;
	adjMat[j][i] = 0;
}

int Graph_Matrix::size()
{
	return vertices.size();
}

void Graph_Matrix::print()
{
	cout << "vertices = ";
	for (vector<int>::iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		cout << *i << "\t";
	}
	cout << endl;
	cout << "adjMat:"<<endl;

	/*
	for (vector<int>::iterator i = vertices.begin(); i == vertices.end(); i++)
	{
		//vector<int> temp = i;
		for (vector<int>::iterator j = vertices.begin(); j == vertices.end(); j++)
		{
			cout << *i << "\t";
		}
	}
	*/
	for (int i=0; i < adjMat.size(); i++)
	{
		vector<int> temp = adjMat[i];
		for (int j = 0; j < temp.size(); j++)
		{
			cout << temp[j]<<"\t";
		}
		cout << endl;
	}
	
}
