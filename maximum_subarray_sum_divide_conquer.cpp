#include<iostream>
#include<vector>
using namespace std;

int maxCrossing(vector<int> nums,int l,int m,int r){
    int sum = 0;
    int sumLeft = -1000000;
    for(int i=m;i>=l;i--){
        sum+=nums[i];
        if(sum>sumLeft) sumLeft = sum;
    }
    sum = 0;
    int sumRight= 0;
    for(int i=m+1;i<=r;i++){
        sum+=nums[i];
        if(sum>sumRight) sumRight = sum;
    }
    return max(sumRight+sumLeft,max(sumLeft,sumRight));
}
int subarraySum(vector<int> nums,int l,int r){
    if(l==r){
        return nums[l];
    }
    int m = l + (r-l)/2;
    int maxLeft=  subarraySum(nums,l,m);
    int maxRight = subarraySum(nums,m+1,r);
    int maxCrossingItem = maxCrossing(nums,l,m,r);
    return max(maxLeft,max(maxRight,maxCrossingItem));
}
int main(){
    vector<int> nums = {2, 3, 4, 5, 7};
    int res = subarraySum(nums,0,nums.size()-1);
    cout << res << endl;
    return 0;
}
