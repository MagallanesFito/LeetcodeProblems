#include<iostream>
#include<vector>
using namespace std;

int dp[1002];
bool divisorGameUtil(int N) {
    //if Alice gets 1, she looses
    if(N<=1) return false;
    if(dp[N]!=-1) return dp[N];
    for(int i=1;i<=N/2;i++){
        if(N%i == 0){
            if(!divisorGameUtil(N-i)){
                return dp[N] = true;
            }

        }
    }
    return dp[N] = false;

}
bool divisorGame(int N) {
    for(int i=0;i<1002;i++) dp[i] = -1;
    return divisorGameUtil(N);
}
int main(){
    cout << divisorGame(2) << endl;;
    return 0;
}


