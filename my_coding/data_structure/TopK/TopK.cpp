#include <iostream>
#include "Heap.h"
//<algorithm>
using namespace std;

int main()
{
    //vector<int> tmp;
    //tmp.push_back(1);
    //tmp.push_back(2);
    Heap topk;
    int count=0;
    cout << "取top3元素" << endl;
    while (true)
    {
        cout << "输入一个数据：-1为结束" << endl;
        int i;
        cin >> i;
        if (i == -1)
            break;
        count++;
        topk.push(i);
        continue;
        if (count > 3)
            topk.push(i);
        else
            topk.push(i);
    }
    vector<int> tmp= topk.tovector();
    for (int i = 1; i <= tmp.size(); i++)
    {
        cout << tmp[i - 1] << endl;
    }
    topk.pop();

    tmp = topk.tovector();
    for (int i = 1; i <= tmp.size(); i++)
    {
        cout << tmp[i - 1] << endl;
    }
    
}

