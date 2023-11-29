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