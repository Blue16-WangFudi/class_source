#include <iostream>
#include <vector>
using namespace std;

ostream &operator<<(ostream &out, vector<int> nums)
{
    int size = nums.size();
    cout << "Vector:";
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << "\t";
    }
}

void insertionSort(vector<int> &nums)
{
    int size = nums.size();
    for (int i = 1; i < size - 1; i++)
    {
        int base = nums[i];
        int j = i - 1; // j的意义：选定当前要判断是否移动的nums[j]
        while (j >= 0 && nums[j] > base)
        {
            nums[j + 1] = nums[j];
            // 向前移动一位
            j--;
        }
        // 让base插入（j+1：撤销j--的影响）
        nums[j + 1] = base;
    }
}

int main()
{
    vector<int> in = {4, 0, 1, 3, 1, 5, 2};
    vector<int> in2 = {0, 1, 1, 2, 3, 4, 5};
    insertionSort(in);
    cout << in2;
    return 0;
}