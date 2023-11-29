#include <iostream>
#include <vector>
using namespace std;

ostream &operator<<(ostream &out, vector<int> nums)
{
    int size = nums.size();
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
            cout << nums[i] << ",";
        else
            cout << nums[i];
    }
    cout << "]";
    return out;
}