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

/*冒泡排序：flag版*/
void bubbleSort(vector<int> &nums) {
    int size=nums.size();
    bool exchange=false;
    for(int i=size-1;i>0;i--){
        //单次冒泡
        for(int j=0;j<i;j++)
        {
            //从小到大排序
            if(nums[j]>nums[i])
            {
                //冒泡一次
                swap(nums[j],nums[i]);
                exchange=true;
            }
        }
        if(exchange==false)
        {
            break;
        }
        
    }
}

int main(){
    vector<int> in={4,0,1,3,1,5,2};
    vector<int> in2={0,1,1,2,3,4,5};
    bubbleSort(in2);
    cout<<in2;
}