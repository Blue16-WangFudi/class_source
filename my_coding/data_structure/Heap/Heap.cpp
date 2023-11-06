#include <iostream>
#include "myHeap.h"
using namespace std;
int main()
{
    Heap test;
    //cout << "Hello World!\n";
    for (int i = 1; i <= 10; i++)
    {
        test.push(i);
    }
    //cout << "Hello World!\n";
    vector<int> ret=test.toVector();
    
    for (int i = 1; i <= ret.size(); i++)
    {
        cout << ret[i - 1] << endl;
    }

}


