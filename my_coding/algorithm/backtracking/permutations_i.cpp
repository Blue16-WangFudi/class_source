/**
 * File: permutations_i.cpp
 * Created Time: 2023-04-24
 * Author: Krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

vector<vector<int>> result; // 存储所有结果

void backtracking(vector<int> &choice, vector<bool> &selected, vector<int> path)
{
    if (path.size() == choice.size()) // 所有选择遍历完了，可以返回和添加res了
    {
        result.push_back(path);
        return;
    }
    unordered_set<int> duplicated;
    for (int i = 0; i < 3; i++)
    {
        // 如果没有被选中且没有被添加过
        if (!selected[i] && (duplicated.find(choice[i]) == duplicated.end()))
        {
            // duplicated用处：把已经有了的元素添加进去，然后再添加一个减枝条件
            //  如果没有选择过，就选择这一个，继续往下走（递归树）
            duplicated.emplace(choice[i]); // 记录选择过的元素值
            selected[i] = true;
            path.push_back(choice[i]);
            backtracking(choice, selected, path);
            // 完成了，往上回溯
            path.pop_back();
            selected[i] = false;
        }
    }
}

vector<vector<int>> permutationsI(vector<int> &nums)
{
    vector<int> path;      // 记录尝试的路径
    vector<bool> selected; // 记录是否所有尝试都被试探
    vector<int> choice;    // 所有试探的可能性
    choice = nums;         // 1 2 3三种选择，对应selected
    for (int i = 0; i < choice.size(); i++)
    {
        selected.push_back(false);
    }
    backtracking(choice, selected, path);
    return result;
}
/* Driver Code */
int main()
{
    vector<int> nums = {1, 1, 3};

    vector<vector<int>> res = permutationsI(nums);

    cout << "输入数组 nums = ";
    printVector(nums);
    cout << "所有排列 res = ";
    printVectorMatrix(res);

    return 0;
}
