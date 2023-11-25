#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    int height;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;


void avlInsert(TreeNode** T, int data) {
    //这里的T为根节点的地址的地址，*T为访问根节点的地址，(*T)->是对根节点进行操作
    if (*T == NULL) {
        //初始化根节点（相对的根节点）
        *T = (TreeNode*)malloc(sizeof(TreeNode));
        (*T) -> data = data;
        (*T) -> height = 0;
        (*T) -> lchild = NULL;
        (*T) -> rchild = NULL;
    }
    else if (data < (*T) -> data) {
        //这里是这个意思：传递左节点的地址的地址，也是一个二级指针。注意其中的运算顺序。avlInsert(&((*T) -> lchild), data);
        avlInsert(&(*T) -> lchild, data);
    }
    else if (data > (*T) -> data) {
        avlInsert(&(*T) -> rchild, data);
    }
}

void preOrder(TreeNode* T) {
    if (T) {
        printf("%d ", T -> data);
        preOrder(T -> lchild);
        preOrder(T -> rchild);
    }
}

int main() {
    TreeNode* T = NULL;//T为根节点的地址
    int nums[5] = {1,8,6,7,10};
    for (int i = 0; i < 5; i++) {
        avlInsert(&T, nums[i]);//&T为取根节点的地址（T）的地址
    }
    preOrder(T);
    printf("\n");
}