#include "../utils/common.hpp"


// 给定一个vector，包含12348，把这些数据移动到另一个vector上

//移动src中顶端的元素到tar上
void move(vector<int> &src,vector<int> &tar){
    //取出src中的一个元素
    int last=src[src.size()-1];
    src.pop_back();
    tar.push_back(last);
}


void dfs(int num,vector<int> &A,vector<int> &B,vector<int> &C){
    //终止条件
    if(num==1){
        move(A,C);
        return;
    }
    //第一步，把n-1个从A移动到C最后到B
    dfs(num-1,A,C,B);
    //第二步，把A上剩下的一个直接移动到C
    move(A,C);
    //第三步：(全部移动完成)把在B上的通过A（此时A是空的）移动到C
    dfs(num-1,B,A,C);
}
int main()
{
    vector<int> A = {5, 4, 3, 2, 1};
    vector<int> B = {};
    vector<int> C = {};
    dfs(A.size(),A,B,C);
    //printVector(C);
    cout << "A = " << A;
    cout << "B = " << B;
    cout << "C = " << C;
    
}