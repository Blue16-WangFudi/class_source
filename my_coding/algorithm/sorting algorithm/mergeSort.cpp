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
void merge(vector<int> &nums, int left, int mid, int right)
{
    // 区间：[left,mid]和[mid+1,right]
    // 取出两个区间的数据，是相邻的
    vector<int> tmp(nums.begin() + left, nums.begin() + right + 1);
    // 计算两个区间在tmp中的相对位置
    int leftstart = left - left, leftend = mid - left ;
    int rightstart = mid - left + 1, rightend = right - left;
    int i = leftstart, j = rightstart; // ij为指针
    // 逐个遍历对应nums区间
    for (int k = left; k <= right; k++)
    {
        if(j>rightend){
            nums[k]=tmp[i++];
            continue;
        }
        if(i>leftend){
            nums[k]=tmp[j++];
            continue;
        }
        //取左边的情况：左边元素k<右边元素k；右边已经读完，没有了
        if(tmp[i]<=tmp[j]){
            nums[k]=tmp[i++];
            continue;
        }
        //取右边的情况：左边元素k>右边元素k；左边已经读完，没有了
        if(tmp[i]>tmp[j]){
            nums[k]=tmp[j++];
            continue;
        }
        

       /*
       // 若“左子数组已全部合并完”，则选取右子数组元素，并且j++
        if (i > leftend)
        nums[k] = tmp[j++];
        // 否则，若“右子数组已全部合并完”或“左子数组元素<= 右子数组元素”，则选取左子数组元素，并且i++
        else if (j > rightend || tmp[i] <= tmp[j])
        nums[k] = tmp[i++];
        // 否则，若“左右子数组都未全部合并完”且“左子数组元素> 右子数组元素”，则选取右子数组元素，并且j++
        else
        nums[k] = tmp[j++];
        */

    }
}
void mergeSort(vector<int> &nums, int left, int right)
{
    if(left>=right){
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums,left,mid,right);
}
int main()
{
    vector<int> tmp = {1, 2, 5, 7, 4, 9, 3, 7,3,3,2};
    mergeSort(tmp,0,tmp.size()-1);
    //merge(tmp,1,3,5);//[2,5,7,4,9]
    cout<<tmp;
}