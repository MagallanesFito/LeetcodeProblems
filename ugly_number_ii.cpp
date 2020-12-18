#include<iostream>
#include<vector>
using namespace std;

int dp[2000];
int nthUglyNumber(int n) {
    vector<int> p2 = {1};
    vector<int> p3 = {1};
    vector<int> p5 = {1};
    vector<int> res(n,0);
    res[0] =1;
    int i2 = 1;
    int i3 = 1;
    int i5 = 1;
    for(int i=1;i<n;i++){
        p2.push_back(2*res[i-1]);
        p3.push_back(3*res[i-1]);
        p5.push_back(5*res[i-1]);
        int m = min(p2[i2],min(p3[i3],p5[i5]));
        if(m==p2[i2]) res[i] = p2[i2++];
        if(m==p3[i3]) res[i] = p3[i3++];
        if(m==p5[i5]) res[i] = p5[i5++];
    }
    return res[n-1];
}
int main(){
    int res = nthUglyNumber(10);
    cout <<res << endl;
    return 0;
}
