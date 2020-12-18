#include<iostream>
using namespace std;


int dp[1000][1000];
//recursive
int solveRecur(int n,int h){
    if(n==1) return h;
    if(h==0) return 0;
    if(h==1) return 1;

    int minimum = 100000;
    for(int x=1;x<=h;x++) minimum = min(minimumm,1+max(solveRecur(n,h-x),solveRecur(n-1,x-1)));
    return minimum;

}
//top down solution.
int solveRecurUtil(int n,int h){
    if(n==1) return h;
    if(h==0) return 0;
    if(h==1) return 1;

    int minimum = 100000;
    if(dp[n][h] != -1) return dp[n][h];
    for(int x=1;x<=h;x++) minimum = min(minimumm,1+max(solveRecur(n,h-x),solveRecur(n-1,x-1)));
    return dp[n][h] = minimum;

}
int solveRecursive(int n,int h){
    for(int i=0;i<1000;i++) for(int j=0;j<1000;j++) dp[i][j] = -1;
    return solveRecurUtil(n,h);
}
//bottom up dp
int solve(int n,int k){
    int dp[n+1][k+1];
    for(int i=0;i<=k;i++) dp[0][i] = 0;
    for(int i=0;i<=k;i++) dp[1][i] = i;
    for(int j=0;j<=n;j++) dp[j][0] = 0;

    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            int minimum = 100000;
            for(int x=1;x<=j;x++){
                minimum = min(minimum,1+max(dp[i][j-x],dp[i-1][x-1]));
            }
            dp[i][j] = minimum;
        }
    }
    return dp[n][k];
}
int main(){
    int eggs = 3;
    int floors = 6;

    int res = solve(eggs,floors);
    cout << res << endl;
}
