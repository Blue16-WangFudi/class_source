#include "operation.h"

int main() {
	operation list;
	//构造二叉树
	//list.Build();
	list.Create_Tree();
	//前序遍历
	cout << "数据遍历（DFS）：" << endl;
	list.Build_1();

	return 0;
}