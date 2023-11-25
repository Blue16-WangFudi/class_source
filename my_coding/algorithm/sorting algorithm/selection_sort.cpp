#include <iostream>
#include <vector>
using namespace std;

ostream& operator<<(ostream& out,vector<int> nums){
    int size=nums.size();
    cout<<"Vector:";
    for(int i=0;i<size;i++){
        cout<<nums[i]<<"\t";
    }
}

void selectionSort(vector<int> &nums) {
    int n=nums.size();
    //[0,n-1]，从小到达
    for(int i=0;i<n;i++){
        int k=i;
        for(int j=i+1;j<n;j++){
            //最小的元素与当前选定的元素交换
            if(nums[k]<nums[j])
            {
                k=j;//重置最小index
            }
            swap(nums[k],nums[j]);
        }
    }
}

int main()
{
    vector<int> in={4,1,3,1,5,2};
    selectionSort(in);
    cout<<in;
}
