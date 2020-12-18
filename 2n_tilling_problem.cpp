#include<iostream>
using namespace std;

int solveRecursive(int n){
    if(n==0) return 0;
    if(n==1 ) return 1;
    //if(dp[n] != -1) return dp[n];
    return solveRecursive(n-1) + solveRecursive(n-2);
}
int dp[100];
//top down dp
int solveRecurUtil(int n){
    if(n==0) return 0;
    if(n==1 ) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = solveRecurUtil(n-1) + solveRecurUtil(n-2);
}
int solveRecur(int n){
    for(int i=0;i<100;i++) dp[i] = -1;
    return solveRecurUtil(n);
}
//bottom up dp
int solve(int n){
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main(){
    int n = 4;
    int res = solveRecur(n);
    cout << res << endl;
}

