#include<iostream>
#include<vector>
using namespace std;

//top-down dp
int dp[50];
int climbStairs(int n) {
    if(n==0) return 1;
    if(n==1) return 1;
    if(dp[n] != 0) return dp[n];
    return dp[n] = climbStairs(n-2) + climbStairs(n-1);
}

int climbStairs(int n) {
    dp[0]  = 1;
    dp[1] = 1;
    if(n<=1) return 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-2] + dp[i-1];
    }
    return dp[n];
}
int main(){
    int a = climbStairsBottom(3);
    cout << a << endl;
    return 0;
}

