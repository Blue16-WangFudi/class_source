#include <iostream>
#include "TreeNodeClass.h"
using namespace std;
int main()
{
    TreeNodeA t1;
    cout << "演示：TreeNode\n";
    //t1.LoadTree();
    for(int i=1;i<=10;i++)
        t1.Insert(i);
    t1.Output_BFS();
    TreeNode* root = t1.getRootNode();
    TreeNode* result = t1.Search_Node(root, 10);
    cout<<"当前查找到的地址，取出val："<<result->val<<endl;
    t1.Delete_Node(t1.getRootNode(), 6);
    //t1.remove(t1.getRootNode(), 7);
    t1.Output_BFS();
    
}