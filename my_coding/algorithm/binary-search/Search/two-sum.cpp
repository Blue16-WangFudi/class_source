#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
/*
给定一个整数数组nums 和一个目标元素target ，请在数组中搜索“和”为target 的两个元
素，并返回它们的数组索引。返回任意一个解即可。
*/

// 方法1：暴力枚举
vector<int> twoSumBruteForce(vector<int> &nums, int target)
{
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (nums[i] + nums[j] == target)
                return {i, j};
        }
    }
    return {};
}
// 方法2：借助哈希表
vector<int> twoSumHashTable(vector<int> &nums, int target)
{
    // 获取元素大小
    int size = nums.size();
    // 先放入哈希表
    unordered_map<int, int> dic;
    // 先插入，后查找
    for (int i = 0; i < size; i++)
    {
        dic.emplace(nums[i], i);
    }

    cout<<"abcdef"<<endl;
    /*
    unordered_map<int,int>::iterator aaa=dic.end();
    cout<<aaa->first<<"："<<aaa->second<<endl;
    */
    // 遍历每个元素，找另一个，注意：end是map的尾部,没有实际元素
    for (int i = 0; i < size; i++)
    {
        unordered_map<int,int>::iterator aaa=dic.find(target-nums[i]);
        //判断是否找到
        if(aaa!=dic.end()){
            //可以这样：list[i]
            return {i,aaa->second};
        }
    }
    return {};
}
ostream &operator<<(ostream &out, vector<int> j)
{
    cout << "数组[0] = " << j[0] << "，数组[1] = " << j[1] << endl;
    return out;
}
int main()
{
    vector<int> data = {1, 4, 9, 16, 25};
    int target = 13;
    vector<int> ret = twoSumHashTable(data, target);
    cout << ret;
}