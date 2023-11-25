#include <iostream>
#include <vector>
#include <unordered_map>
#include "util.hpp"
using namespace std;

vector<int> twoSumHashTable(vector<int> &nums, const int target)
{
    // 任务：给定一个整数数组nums 和一个目标元素target ，请在数组中搜索“和”为target 的两个元素
    // 并返回它们的数组索引。返回任意一个解即可。
    // Sum,Index
    unordered_map<int, int> hashmap;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        // 没有就添加，有就返回
        if (hashmap.find(target - nums[i]) != hashmap.end())
        {
            // 找到了
            return {nums[i], target - nums[i]};
        }
        else
        {
            hashmap.emplace(nums[i], i);
        }
    }
    return {};
}

int main()
{
    vector<int> in = {1, 2, 5, 8, 14, 17};
    cout << twoSumHashTable(in, 13);
}