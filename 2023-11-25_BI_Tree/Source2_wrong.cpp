#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    int height;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

void avlInsert(TreeNode* T, int data) {
    if (T == NULL) {
        T = (TreeNode*)malloc(sizeof(TreeNode));
        T -> data = data;
        T -> height = 0;
        T-> lchild = NULL;
        T -> rchild = NULL;
    }
    else if (data < T -> data) {
        avlInsert(T -> lchild, data);
    }
    else if (data > T-> data) {
        avlInsert(T -> rchild, data);
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
    TreeNode* T = NULL;
    int nums[5] = {1,8,6,7,10};
    for (int i = 0; i < 5; i++) {
        //问题见README.md，其实我想用一级指针试试，但是最近非常忙，到时候空了再说。先恳请大佬来看看。
        avlInsert(T, nums[i]);
    }
    preOrder(T);
    printf("\n");
}