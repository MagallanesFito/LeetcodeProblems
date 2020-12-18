#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> vvi;

//Define custom * operator
struct Matrix{
    vvi a;
    Matrix operator *(Matrix other){
        Matrix res = {{{0,0},{0,0}}};
        res.a[0][0] = a[0][0]*other.a[0][0] + a[0][1]*other.a[1][0];
        res.a[0][1] = a[0][0]*other.a[0][1] + a[0][1]*other.a[1][1];
        res.a[1][0] = a[1][0]*other.a[0][0] + a[1][1]*other.a[1][0];
        res.a[1][1] = a[1][0]*other.a[0][1] + a[1][1]*other.a[1][1];
        return res;
    }
};

void printM(vector<vector<int>> a){
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[0].size();j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
//siempre es de 2x2
vector<vector<int>> multiply(vector<vector<int>> a,vector<vector<int>> b){
    vector<vector<int>> res = {{0,0},{0,0}};
    res[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    res[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    res[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    res[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];
    return res;
}

vector<vector<int>> power(vector<vector<int>> m,int b){
    vector<vector<int>> res = {{1,0},{0,1}};
    while(b>0){
        if(b%2==1){
            res = multiply(res,m);
        }
        m = multiply(m,m);
        b = b/2;
    }
    return res;
}

int climbStairs(int n){
    if(n == 0 || n==1) return 1;
    vector<vector<int>> M = {{1,1},{1,0}};
    vector<vector<int>> res = power(M,n-1);
    int dp0 = 1;
    int dp1 = 1;
    int result = dp1*res[0][0] + dp0*res[1][0];
    return result;
}
int main(){
    int res = climbStairs(10);
    cout << res<< endl;
    return 0;
}


