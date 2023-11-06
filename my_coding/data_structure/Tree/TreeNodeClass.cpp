
#include "TreeNodeClass.h"
#include <iostream>
#include<queue>
using namespace std;
//������ʾ��ʹ������
TreeNodeA::TreeNodeA()
{

}
void TreeNodeA::LoadTree()//֮ǰ�������õģ���Ҫ�ҵ���
{
    //������5���ڵ�
    n1 = new TreeNode(1);

    n2 = new TreeNode(2);

    n3 = new TreeNode(3);

    n4 = new TreeNode(4);

    n5 = new TreeNode(5);
    //��������
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

}
void TreeNodeA::Output_BFS()//��������㷨,�ö��� Breadth-First Search
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
    cout << node->val << endl;//�������λ�õĲ�ͬ����Ϊǰ�����������������������
}

void TreeNodeA::Output_DFS()//�������,�ݹ��˼��
{
    Search(root);
}
void TreeNodeA::Insert(int num)//����һ�����ݣ��������������
{
    if (root == nullptr)
    {
        root = new TreeNode(num);//���û�������Ǿ��ȴ���һ�����ڵ�
        return;
    }
    TreeNode* cur=root,*pre=nullptr;//��ǰ�ڵ�
    //�����������ҵ�Ҫ�����ĸ�λ�ã�Ȼ�����,root�Ǹ��ڵ�
    while (cur!=nullptr)
    {
        pre = cur;//�������ǰ��һ���ڵ�
        //���λ����λ�����ǾͲ������ˣ�ֱ�Ӳ���
        //���̫���Ǿ����ұ��ߣ����̫С�����������
        if (cur->val == num)
            return;
        if (cur->val > num)//С�ˣ��������
            cur = cur->left;
        else
            cur = cur->right;//���ˣ����ұ���
        //һֱ���ң�ֱ��cur��Ϊnullptr��Ҳ����ת����Ҷ
    }
    //����ڵ�
    TreeNode* node = new TreeNode(num);
    if (pre->val < num)
        pre->right = node;
    else
        pre->left = node;
}

TreeNode* TreeNodeA::Search_Node(TreeNode* node,int val)//����ɷ�װ��������Ӧ��ֵ�Ľڵ�,rootΪ���ڵ�
{
    TreeNode* work=node;
    while (work != nullptr)
    {
        if (work->val == val)
            break;
        if (work->val < val)
                work = work->right;
        else if (work->val > val)//һ��Ҫ��else����Ȼ����ĸ��������ȡ���жϵ�ʱ��ͻᱨ��ָ��
            work = work->left;

    }
    return work;
}

void TreeNodeA::Delete_Node(TreeNode* node, int val)
{
    //�ⶼ�Ƕ���������ˣ�Ϊʲô����Ҫ��ô���ӣ�ֱ�Ӷ��ֲ��Ҿ����ˡ�
    //ֻ��һ�����ڵ㣬ֱ��ɾ��
    if (node->val == val && node->left==nullptr && node->right==nullptr)
    {
        delete node;
        return;
    }
    //���ҵ���Ӧ�ڵ㣬���ָ�롣��Ȼ�Ƕ��ֲ���
    TreeNode* current=node;
    TreeNode* previous = node;//�����һ���ڵ㣬���ڸ���
    while (current != nullptr)
    {
        if (current->val == val)
            break;
        previous = current;
        if (current->val > val)//Ҫ���ҵĽڵ������е�С�������
            current = current->left;
        if (current->val < val)//�е�����ұ�
            current = current->right;
    }

    cout << "��ǰcurrent->val=" << current->val<<endl;
    cout << "��ǰprevious->val=" << previous->val << endl;

    //��д�򵥵������ɾ��Ҷ
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
    //Ȼ����ɾ������һ���ӽڵ�Ľڵ�

    if (current->left == nullptr || current->right == nullptr)//��һ��Ϊ�վ��У����ǽ�������һ���ӽڵ�
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

    //���ɾ�������ڵ㣺�Ƚϸ���,���������������Ҳ���С����̣�����Ȼ����ǰ��Ҳ��
    if (current->left != nullptr && current->right != nullptr)
    {
        TreeNode *ori = current;
        TreeNode* pre = current;
        TreeNode *cur = current->right;
        //���ﲻ����������һֱ����֧������ߣ��ߵ���ͷ������С
        //����˵����ɽǰ����·�����������ӣ���ʵд����������
        while (cur != nullptr)
        {
            pre = cur;
            if (cur->left != nullptr)
                cur = cur->left;
        }
        //�ҵ���Сֵ����ֵ��
        ori->val = cur->val;
        pre->left = nullptr;
        delete cur;
    }


}

TreeNode* TreeNodeA::getRootNode()
{
    cout << "��ȡ���ڵ�:"<<root;
    return root;
}
/* ɾ���ڵ�*/
void TreeNodeA::remove(TreeNode* root, int num) {//��׼д��
    // ����Ϊ�գ�ֱ����ǰ����
    if (root == nullptr)
        return;
    TreeNode* cur = root, * pre = nullptr;
    // ѭ�����ң�Խ��Ҷ�ڵ������
    while (cur != nullptr) {
        // �ҵ���ɾ���ڵ㣬����ѭ��
        if (cur->val == num)
            break;
        pre = cur;
        // ��ɾ���ڵ���cur ����������
        if (cur->val < num)
            cur = cur->right;
        // ��ɾ���ڵ���cur ����������
        else
            cur = cur->left;
    }
    // ���޴�ɾ���ڵ㣬��ֱ�ӷ���
    if (cur == nullptr)
        return;
    // �ӽڵ�����= 0 or 1
    if (cur->left == nullptr || cur->right == nullptr) {
        // ���ӽڵ�����= 0 / 1 ʱ�� child = nullptr / ���ӽڵ�
        TreeNode* child = cur->left != nullptr ? cur->left : cur->right;
        // ɾ���ڵ�cur
        if (cur != root) {
            if (pre->left == cur)
                pre->left = child;
            else
                pre->right = child;
        }
        else {
            // ��ɾ���ڵ�Ϊ���ڵ㣬������ָ�����ڵ�
            root = child;
        }
        // �ͷ��ڴ�
        delete cur;
    }
    // �ӽڵ�����= 2
    else {
        // ��ȡ���������cur ����һ���ڵ�
        TreeNode* tmp = cur->right;
        while (tmp->left != nullptr) {
            tmp = tmp->left;
        }
        int tmpVal = tmp->val;
        // �ݹ�ɾ���ڵ�tmp
        remove(root,tmp->val);
        // ��tmp ����cur
        cur->val = tmpVal;
    }
}




