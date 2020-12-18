#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

//simple dp solution... can optimize space to dp[5]..
//still O(n) solution
int dp[53][5];

//we can avoid using this function just by updating array inplace...
int sumRow(int row,int col){
    int sum =0;
    for(int i=col;i<5;i++){
        sum+=dp[row][i];
    }
    return sum;
}
int countVowelStrings(int n) {
    for(int i=0;i<5;i++) dp[1][i] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<5;j++){
            dp[i][j] = sumRow(i-1,j);
        }
    }

    return sumRow(n,0);
}
int main(){
    int res = countVowelStrings(33);
    cout << res<< endl;
    return 0;
}
