#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> countBits(int num) {
    vector<int> dp(num+1,0);
    int max_pow = 2;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i=3;i<=num;i++){

        if(i == 2*max_pow) max_pow = max_pow*2;
        dp[i] = 1+dp[i%max_pow];
    }
    //for(auto x:dp) cout << x << " ";
    return dp;
}
int main(){
    vector<int> res = countBits(2);
    return 0;
}

