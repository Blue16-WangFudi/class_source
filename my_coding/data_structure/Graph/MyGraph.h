#pragma once
#include<vector>
using namespace std;
class Graph_Matrix {
private:
	//����࣬�ȿ�����Ҫ��ʲô����
	vector<int> vertices; // �����б�Ԫ�ش�������ֵ����������������������
	vector<vector<int>> adjMat; // �ڽӾ�������������Ӧ�����������������к���(���Ϊ��)
	//��������ƹ��ܣ�����һ��������Ȼ����˳����cpp�ļ���ʵ��
	//Ȼ���ǹ�����������������һ�㶼��
private:
	vector<vector<int>> delete_matrix(vector<vector<int>> matrix, int i, int j);
	vector<int> delete_vector(vector<int> vec, int index);
	vector<vector<int>> delete_vector(vector<vector<int>> vec, int index);//��ʵ����ͨ��ģ�����һ���
	//��ʵ��һ��vector.erase�ķ���������ֱ���Ƴ�һ��Ԫ��
public:
	Graph_Matrix();
	~Graph_Matrix();
	//������������ɾ�Ĳ�
	void addVertex(int val);//���һ������
	void addEdge(int i, int j,float weight);//���һ���ߣ�ijΪ������weightΪȨ��

	void removeVertex(int index);//�Ƴ�һ������
	void removeEdge(int i, int j);//�Ƴ�һ����

	int size();//��ȡ��������
	void print();//��ӡ����

	
};

class Graph_List {
public:
	void hello();
};