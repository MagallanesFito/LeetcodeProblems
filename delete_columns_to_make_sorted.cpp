#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<string> A,int col){
    for(int i=1;i<A.size();i++){
        if(A[i][col] < A[i-1][col]) return false;
    }
    return true;
}
int minDeletionSize(vector<string>& A) {
    //int n = A.size();
    int cont = 0;
    for(int i=0;i<A[0].length();i++){
        if(!isSorted(A,i)) cont++;
    }
    return cont;
}
int main(){
    vector<string> a = {"zyx","wvu","tsr"};
    int res = minDeletionSize(a);
    cout << res << endl;
    return 0;
}
