#include "../../utils/common.hpp"

deque<TreeNode *> seq;               // 遍历节点的序列
vector<TreeNode *> path;             // 记录一串节点构成的路径 TreeNode* [1,7,4]
vector<vector<TreeNode *>> solution; // 存储所有满足的节点

// 回溯法遍历binary tree

// 任务：返回到7的所有path但是不能包括3

//注意看一下同名文件：例题三

//前序遍历
void preOrder(TreeNode* root){
    //设定终止条件，剪枝
    if(root==nullptr || root->val==3){
        return;
    }
    //试探：添加path
    path.push_back(root);
    if(root->val==7)
    solution.push_back(path);
    //往下走
    preOrder(root->left);
    preOrder(root->right);
    //走到尽头，直接退回一级
    path.pop_back();

}

int main()
{
    TreeNode *root = vectorToTree(vector<int>{1, 7, 3, 4, 5, 6, 7});
    cout << "\n初始化二叉树" << endl;
    printTree(root);
    // 开始遍历，前序遍历
    preOrder(root);
    
    cout << "\n输出所有根节点到节点 7 的路径" << endl;
    for (vector<TreeNode *> &path : solution) {
        vector<int> vals;
        for (TreeNode *node : path) {
            vals.push_back(node->val);
        }
        printVector(vals);
    }
    return 0;
}