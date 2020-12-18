#include<iostream>
using namespace std;

#define ios_ ios_base::sync_with_stdio(0);cin.tie(NULL);
int commonChild(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    int dp[2][n+1];
    int bi;
    for(int i=0;i<2;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = 0;
        }
    }

    for(int i=0;i<m;i++){
        bi=i&1;
        for(int j=0;j<=n;j++){
            if(i == j){
                dp[bi][j] = 0;
            }
            else if(s1[i] == s2[j-1]){
                dp[bi][j] = dp[1-bi][j-1] + 1;
            }
            else{
                dp[bi][j] = max(dp[1-bi][j],dp[bi][j-1]);
            }
        }
    }
    return dp[bi][n];
}

int main(){
    ios_
    cout << commonChild("SHINCHAN","NOHARAAA");
    return 0;
}
