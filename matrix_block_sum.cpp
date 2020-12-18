#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
    vector<int> v(mat[0].size(),0);
    vector<vector<int>> cumsum(mat.size(),v);

    vector<vector<int>> res(mat.size(),v);

    for(int i=0;i<mat.size();i++){
        int sum = 0;
        for(int j=0;j<mat[i].size();j++){
            sum+=mat[i][j];
            cumsum[i][j] = sum;
        }
    }

    for(int j=0;j<mat[0].size();j++){
        //int sum = 0;
        for(int i=1;i<mat.size();i++){
            cumsum[i][j] += cumsum[i-1][j];
        }
    }

    int n = mat.size();
    int m = mat[0].size();
    int S,R,T;
    int a,b,c,d;
    int k = K;
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            a = i-k;
            if(a<0) a = 0;
            b = i+k;
            if(b>=n) b = n-1;
            c = j-k;
            if(c<0) c= 0;
            d = j+k;
            if(d >=m) d = m-1;
            S = cumsum[b][d];
            if(c-1<0){
              R = 0;
            }
            else{
              R = cumsum[b][c-1];
            }
            if(a-1<0){
              T = 0;
            }
            else{
             T = cumsum[a-1][d];
            }
            res[i][j] = S - R - T;
            if(R>0 && T > 0) res[i][j]++;
        }

    }
    return res;
}
int main(){
    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
    int k = 1;
    vector<vector<int>> res = matrixBlockSum(m,k);

   for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
