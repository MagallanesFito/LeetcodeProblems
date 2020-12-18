#include<iostream>
using namespace std;

/*void printDP(int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}*/
int dp[102][102];
int solve(int m,int n){
    if(n==1) return 1;
    if(m==1) return 1;

    if(dp[m][n] != -1) return dp[m][n];
    return dp[m][n] = solve(m-1,n) + solve(m,n-1);
}
int uniquePathsTop(int m,int n){
    for(int i=0;i<102;i++)for(int j=0;j<102;j++) dp[i][j] = -1;
    return solve(m,n);
}
int uniquePaths(int m, int n) {
    for(int i=0;i<n;i++)dp[0][i] = 1;
    for(int i=0;i<m;i++)dp[i][0] = 1;

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    //printDP(m,n);
    return dp[m-1][n-1];
}
int main(){
    int m = 3;
    int n = 7;
    int res= uniquePathsTop(m,n);
    cout << res << endl;
    return 0;
}

