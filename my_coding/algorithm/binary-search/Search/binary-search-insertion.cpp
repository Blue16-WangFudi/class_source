#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
int binarysearchinsertion(vector<int> &data, int target)
{
    int ptr1 = 0, ptr2 = data.size() - 1;
    while (ptr1 <= ptr2)
    {
        int middle = (ptr1 - ptr2) / 2 + ptr2;
        if (target > data[middle])
        {
            ptr1 = middle + 1;
        }
        else if (target < data[middle])
        {
            ptr2 = middle - 1;
        }
        else if (target == data[middle])
        {
            return middle;
        }
    }
    return ptr1;
}
int main()
{
    vector<int> a = {1, 3, 5, 7, 9};
    cout << binarysearchinsertion(a, 5) << endl;
}