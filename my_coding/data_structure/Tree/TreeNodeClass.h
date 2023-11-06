
#include <iostream>
#include<queue>
struct TreeNode {//����һ�����Ľڵ�
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};
class TreeNodeA {
private:
    TreeNode* n1, * n2, * n3, * n4, * n5,*root;//rootΪ���ڵ�
public:
    TreeNodeA();
    void LoadTree();
    void Output_BFS();
    void Search(TreeNode* node);
    //void SearchB(TreeNode* node);
    void Output_DFS();
    void Insert(int value);
    TreeNode* Search_Node(TreeNode* node, int val);
    void Delete_Node(TreeNode* node, int val);
    TreeNode* getRootNode();
    void remove(TreeNode* node, int val);
};