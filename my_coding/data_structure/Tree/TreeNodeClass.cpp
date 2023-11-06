
#include "TreeNodeClass.h"
#include <iostream>
#include<queue>
using namespace std;
//树的演示，使用链表
TreeNodeA::TreeNodeA()
{

}
void TreeNodeA::LoadTree()//之前做测试用的，不要乱调用
{
    //创建好5个节点
    n1 = new TreeNode(1);

    n2 = new TreeNode(2);

    n3 = new TreeNode(3);

    n4 = new TreeNode(4);

    n5 = new TreeNode(5);
    //建立链接
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

}
void TreeNodeA::Output_BFS()//广度优先算法,用队列 Breadth-First Search
{
    cout << "Current Tree:----------" << endl;
    queue<TreeNode*> out;
    out.push(root);
    while (out.empty()==false)
    {
        TreeNode* cur = out.front();
        cout << cur->val << endl;
        out.pop();
        if (cur->left != nullptr)
            out.push(cur->left);
        if (cur->right != nullptr)
            out.push(cur->right);
    }
    cout << "----------End.---------" << endl;

}
void TreeNodeA::Search(TreeNode* node)
{
    if (node->left != nullptr)
        Search(node->left);

    if (node->right != nullptr)
        Search(node->right);
    cout << node->val << endl;//根据输出位置的不同，分为前序遍历、中序遍历、后序遍历
}

void TreeNodeA::Output_DFS()//深度优先,递归的思想
{
    Search(root);
}
void TreeNodeA::Insert(int num)//插入一个数据，测试排序二叉树
{
    if (root == nullptr)
    {
        root = new TreeNode(num);//如果没有树，那就先创建一个根节点
        return;
    }
    TreeNode* cur=root,*pre=nullptr;//当前节点
    //分两步：先找到要插入哪个位置，然后插入,root是根节点
    while (cur!=nullptr)
    {
        pre = cur;//保存操作前的一个节点
        //如果位于中位数，那就不用走了，直接插入
        //如果太大，那就往右边走；如果太小，就往左边走
        if (cur->val == num)
            return;
        if (cur->val > num)//小了，往左边走
            cur = cur->left;
        else
            cur = cur->right;//大了，往右边走
        //一直查找，直到cur变为nullptr，也就是转到了叶
    }
    //插入节点
    TreeNode* node = new TreeNode(num);
    if (pre->val < num)
        pre->right = node;
    else
        pre->left = node;
}

TreeNode* TreeNodeA::Search_Node(TreeNode* node,int val)//已完成封装。搜索对应数值的节点,root为根节点
{
    TreeNode* work=node;
    while (work != nullptr)
    {
        if (work->val == val)
            break;
        if (work->val < val)
                work = work->right;
        else if (work->val > val)//一定要加else，不然上面的改完下面读取做判断的时候就会报空指针
            work = work->left;

    }
    return work;
}

void TreeNodeA::Delete_Node(TreeNode* node, int val)
{
    //这都是二叉查找树了，为什么还需要那么复杂？直接二分查找就行了。
    //只有一个根节点，直接删除
    if (node->val == val && node->left==nullptr && node->right==nullptr)
    {
        delete node;
        return;
    }
    //查找到对应节点，获得指针。当然是二分查找
    TreeNode* current=node;
    TreeNode* previous = node;//存放上一个节点，便于更改
    while (current != nullptr)
    {
        if (current->val == val)
            break;
        previous = current;
        if (current->val > val)//要查找的节点数据有点小，在左边
            current = current->left;
        if (current->val < val)//有点大，在右边
            current = current->right;
    }

    cout << "当前current->val=" << current->val<<endl;
    cout << "当前previous->val=" << previous->val << endl;

    //先写简单的情况：删除叶
    if (current->left == nullptr && current->right == nullptr)
    {
        if (previous->left == current)
        {
            previous->left = nullptr;
        }
        else
            previous->right = nullptr;
        delete current;
        return;
    }
    //然后是删除具有一个子节点的节点

    if (current->left == nullptr || current->right == nullptr)//有一个为空就行，就是仅仅具有一个子节点
    {
        if (previous->left == current)
        {
            if (current->left != nullptr)
                previous->left = current->left;
            else
                previous->left = current->right;
        }
        else
        {
            if (current->left != nullptr)
                previous->right = current->left;
            else
                previous->right = current->right;
        }
        delete current;
        return;
    }

    //最后删除两个节点：比较复杂,这里我是搜索的右侧最小（后继），当然你找前驱也行
    if (current->left != nullptr && current->right != nullptr)
    {
        TreeNode *ori = current;
        TreeNode* pre = current;
        TreeNode *cur = current->right;
        //这里不是搜索，是一直往右支的左侧走，走到尽头就是最小
        //所以说车到山前必有路，看起来复杂，其实写起来就这样
        while (cur != nullptr)
        {
            pre = cur;
            if (cur->left != nullptr)
                cur = cur->left;
        }
        //找到最小值，赋值给
        ori->val = cur->val;
        pre->left = nullptr;
        delete cur;
    }


}

TreeNode* TreeNodeA::getRootNode()
{
    cout << "获取根节点:"<<root;
    return root;
}
/* 删除节点*/
void TreeNodeA::remove(TreeNode* root, int num) {//标准写法
    // 若树为空，直接提前返回
    if (root == nullptr)
        return;
    TreeNode* cur = root, * pre = nullptr;
    // 循环查找，越过叶节点后跳出
    while (cur != nullptr) {
        // 找到待删除节点，跳出循环
        if (cur->val == num)
            break;
        pre = cur;
        // 待删除节点在cur 的右子树中
        if (cur->val < num)
            cur = cur->right;
        // 待删除节点在cur 的左子树中
        else
            cur = cur->left;
    }
    // 若无待删除节点，则直接返回
    if (cur == nullptr)
        return;
    // 子节点数量= 0 or 1
    if (cur->left == nullptr || cur->right == nullptr) {
        // 当子节点数量= 0 / 1 时， child = nullptr / 该子节点
        TreeNode* child = cur->left != nullptr ? cur->left : cur->right;
        // 删除节点cur
        if (cur != root) {
            if (pre->left == cur)
                pre->left = child;
            else
                pre->right = child;
        }
        else {
            // 若删除节点为根节点，则重新指定根节点
            root = child;
        }
        // 释放内存
        delete cur;
    }
    // 子节点数量= 2
    else {
        // 获取中序遍历中cur 的下一个节点
        TreeNode* tmp = cur->right;
        while (tmp->left != nullptr) {
            tmp = tmp->left;
        }
        int tmpVal = tmp->val;
        // 递归删除节点tmp
        remove(root,tmp->val);
        // 用tmp 覆盖cur
        cur->val = tmpVal;
    }
}




