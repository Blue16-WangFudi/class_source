
#include <iostream>
#include<queue>
struct TreeNode {//定义一个树的节点
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};
class TreeNodeA {
private:
    TreeNode* n1, * n2, * n3, * n4, * n5,*root;//root为根节点
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