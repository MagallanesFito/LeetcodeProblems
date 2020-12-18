#include<iostream>
#include<vector>
using namespace std;

int dp[102];

//top down, easier to make from recursion to dp
int robUtil(vector<int> nums,int start,int endhouse){
    if(start >= endhouse) return 0;
    if(start == endhouse-1) return nums[start];
    if(dp[start]!=-1) return dp[start];
    for(int i=start;i<nums.size();i++){
        return dp[start] = max(nums[i]+robUtil(nums,start+2,endhouse),robUtil(nums,start+1,endhouse));
    }
    return dp[start];
}
int rob(vector<int>& nums) {
    for(int i=0;i<102;i++) dp[i] = -1;
    int a =  robUtil(nums,0,nums.size()-1);
    for(int i=0;i<102;i++) dp[i] = -1;
    int b = robUtil(nums,1,nums.size());
    return max(a,b);
}
int main(){
    vector<int> nums = {1,2,3,1};
    int res = rob(nums);
    cout << res << endl;
    return 0;
}



