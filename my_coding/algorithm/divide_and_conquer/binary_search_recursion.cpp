#include <iostream>
#include <vector>
using namespace std;
//给定一个长度为𝑛 的有序数组nums ，数组中所有元素都是唯一的，请查找元素target 。
class myobj{
    int a;
    //nums为总数组，num为搜索数据，begin/end为index，返回值为找到的index
    //0   3
public:
    int binarysearch_my(vector<int> &nums,int num,int begin,int end){
        //结束递归条件：搜索区间只有一个元素了
        if(begin>end){
            return -1;//未找到
        }
        //开始查找，排除一半
        //计算中点坐标
        int mid=(begin+end)/2;
        if(nums[mid]>num){
            //num太小了，应该在左边
            binarysearch_my(nums,num,begin,mid-1);//注意区间中点的处理
        }
        else if(nums[mid]<num){
            binarysearch_my(nums,num,mid+1,end);
        }
        else {
            return mid;

        }
        
    }
};
int main(){
    myobj ob;
    vector<int> data={1,4,6,8,9,10,25,47,89,100,101};
    cout<<ob.binarysearch_my(data,10111,0,data.size()-1);

}