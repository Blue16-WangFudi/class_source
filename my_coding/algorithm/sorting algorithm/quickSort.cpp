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
    cout << endl;
    return out;
}

int partition_old(vector<int> &nums, int left, int right)
{
    // 初始化变量，选取区间最左边为参照
    int i = left, j = right;
    // 当左边小于右边，区间有元素，继续
    int target=nums[left];
    while (i < j)
    {
        while (i<j && nums[j] >= target)
        {
            j--;
        }
        while (i<j && nums[i] <= target) // ？一定要加上后面的“&&”吗
        {
            i++;
        }



        swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[i]);
    // 当左边等于右边，也就是跳出循环了，可以把参照填写过去了
    return i;
}

/* 哨兵划分 */
int partition_new(vector<int> &nums, int left, int right)
{
    // 以 nums[left] 作为基准数
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && nums[j] >= nums[left])
            j--; // 从右向左找首个小于基准数的元素
        while (i < j && nums[i] <= nums[left])
            i++;                // 从左向右找首个大于基准数的元素
        swap(nums[i], nums[j]); // 交换这两个元素
    }
    swap(nums[left], nums[i]); // 将基准数交换至两子数组的分界线
    return i;                  // 返回基准数的索引
}

int partition(vector<int> &nums, int left, int right)
{
    return partition_old(nums, left, right);
}

void quickSort(vector<int> &nums, int left, int right)
{
    if(left>=right)
    {
        return;
    }
    int mid = partition(nums, left, right);
    quickSort(nums, left, mid - 1);
    quickSort(nums, mid + 1, right);
}

int main()
{
    vector<int> data = {2, 4, 9,7,1, 0, 3, 5};
    quickSort(data, 0, data.size() - 1);
    cout << data;
}
