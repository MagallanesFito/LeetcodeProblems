#include<iostream>
#include<vector>
using namespace std;

int pascal(int i,int j){
    if(j == 1 || i==j){
        return 1;
    }
    return pascal(i-1,j-1) + pascal(i-1,j);
}
vector<int> getRow(int rowIndex){
    vector<int> res;
    for(int i=1;i<=rowIndex+1;i++){
        res.push_back(pascal(rowIndex+1,i));
    }
    return res;
}
void printRes(vector<int> a){
    for(auto x: a){
        cout << x << " ";
    }
    cout << endl;
}
int tailRecursion(int x){
    if(x == 0){
        return 0;
    }
    return 1+tailRecursion(x-1);
}
int main(){
   cout << tailRecursion(3) << " ";
   return 0;
}
