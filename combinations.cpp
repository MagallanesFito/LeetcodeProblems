#include<iostream>
#include<vector>
using namespace std;

void printcurrent(vector<int> cur){
    for(auto x:cur){
        cout << x << " ";
    }
    cout << endl;
}


vector<vector<int>> res;
vector<int> current;

void combineUtil(int n,int k,int start){
    if(current.size() == k){
        //printcurrent(current);
        res.push_back(current);
        return;
    }
    for(int i=start;i<=n;i++){
        current.push_back(i);
        combineUtil(n,k,i+1);
        current.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    combineUtil(n,k,1);
    return res;
}
int main(){
    vector<vector<int>> res = combine(4,2);
    for(auto cv:res){
        printcurrent(cv);
    }
    return 0;
}

