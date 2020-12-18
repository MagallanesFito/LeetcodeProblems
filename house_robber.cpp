#include<iostream>
#include<vector>
using namespace std;

int dp[102];

//top down, easier to make from recursion to dp
int robUtil(vector<int> nums,int start){
    if(start >= nums.size()) return 0;
    if(start == nums.size()-1) return nums[start];
    if(dp[start]!=-1) return dp[start];
    for(int i=start;i<nums.size();i++){
        return dp[start] = max(nums[i]+robUtil(nums,start+2),robUtil(nums,start+1));
    }
    return dp[start];
}
//bottom up
int rob(vector<int> nums){
    int dp[102];
    dp[0] = nums[0];
    dp[1] = nums[1];
    for(int i=2;i<nums.size();i++){
        dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
        //cout << dp[i] << endl;
    }
    return dp[nums.size()-1];
}
int rob(vector<int>& nums) {
    for(int i=0;i<102;i++) dp[i] = -1;
    return robUtil(nums,0);
}
int main(){
    vector<int> nums = {2,7,9,3,1};
    int res = robBottom(nums);
    cout << res << endl;
    return 0;
}



