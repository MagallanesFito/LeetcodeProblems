#include<iostream>
using namespace std;


int dp[502][502];
int solve(string w1,int n,string w2,int m){
    if(n == 0) return m;
    if(m == 0) return n;

    if(w1[n-1] == w2[m-1]){
        return solve(w1,n-1,w2,m-1);
    }
    else{
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        int up = solve(w1,n-1,w2,m);
        int left = solve(w1,n,w2,m-1);
        int diag = solve(w1,n-1,w2,m-1);
        return dp[n][m] = 1+min(up,min(left,diag));
    }
    return dp[n][m];
}
int minDistance(string word1,string word2){
    for(int i=0;i<502;i++)for(int j=0;j<502;j++) dp[i][j] = -1;
    return solve(word1,word1.length(),word2,word2.length());
}
int minDistanceBottomUp(string word1, string word2) {
    for(int i=0;i<=word1.length();i++) dp[0][i] = i;
    for(int i=0;i<=word2.length();i++) dp[i][0] = i;

    for(int i=1;i<=word2.length();i++){
        for(int j=1;j<=word1.length();j++){
            if(word2[i-1] == word1[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
    }
    return dp[word2.length()][word1.length()];
}
int main(){
    string a = "horse";
    string b = "ros";
    int res = minDistance(a,b);
    cout << res << endl;
    return 0;
}
