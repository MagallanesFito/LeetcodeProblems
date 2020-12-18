#include<iostream>
using namespace std;

int lis(vector<int> arr){
    int n = arr.size();
    int dp[n];

    for(int i=0;i<n;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
    }
    int ans = dp[0];
    for(auto x:dp) ans = max(ans,x);
    return ans;
}
int main(){
    return 0;
}
