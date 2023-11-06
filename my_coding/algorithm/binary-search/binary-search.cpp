#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int binarySearch(vector<int> data, int search)
{
    // 思路：计算中间数，与中间数比较确定取哪边
    int p1 = 0, p2 = data.size() - 1; // 获取两个指针
    int mid = (p1 + p2) / 2;
    // 0 1 2 3 4 5 6 7 8 9
    while (true)
    {
        if (data[mid] == search)
        {
            return mid;
        }
        if (data[mid] < search)
        {
            p1 = mid;
        }
        if (data[mid] > search)
        {
            p2 = mid;
        }
        if (p1 + 1 == p2)
        {
            if (data[p1] == search)
            {
                return p1;
            }
            if (data[data.size() - 1] == search)
            {
                return p2;
            }
            else
            {
                return -1;
            }
        }
        mid = (p1 + p2) / 2;
    }
}
// 双闭区间,先打一遍然后改名称
int binarySearch_2(vector<int> &nums, int target)
{
    int ptr1 = 0, ptr2 = nums.size() - 1; // 两个指针
    while (ptr1 <= ptr2)
    {
        // 这里是大于还是等于？
        int mid = (ptr2 - ptr1) / 2 + ptr1;
        if (target > nums[mid])
        {
            ptr1 = mid + 1; // 自己一定不对，所以不重要可以+1跳过
            continue;
        }
        if (target < nums[mid])
        {
            ptr2 = mid - 1;
            continue;
        }
        else
        {
            // 满足了条件，就是mid了
            return mid;
        }
    }
    return -1;
}
// Shift+alt+f：快速格式化代码
int main()
{
    clock_t start = clock();

    vector<int> data = {47, 82, 95, 102, 458};
    cout << binarySearch(data, 4589);
    return 0 ;
    clock_t end = clock();
    cout << "程序运行时间 = " << end - start << endl;
}