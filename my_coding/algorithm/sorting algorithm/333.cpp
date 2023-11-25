#include <iostream>
using namespace std;
int main()
{
    int a=1,n=9;
    for (int i = 1; i <= n; i++)
    {
        a *= i; // a为阶乘
    }
    cout<<a;
}