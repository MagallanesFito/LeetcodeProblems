#include<iostream>
#include<vector>
using namespace std;

vector<int> sumZeroUtil(int n){
    vector<int> res;
    if(n==1){
        res.push_back(0);
        return res;
    }
    if(n==3){
        res.push_back(-1);
        res.push_back(-2);
        res.push_back(3);
        return res;
    }
    for(int i=1;2*i<=n;i++){
        res.push_back(i);
        res.push_back(-i);
    }
    return res;
}
vector<int> sumZero(int n){
   vector<int> res;
   if(n%2 == 0){
        return sumZeroUtil(n);
   }
   if(n==3){
        return sumZeroUtil(n);
   }
   res = sumZeroUtil(n-3);
   res.push_back(n-3);
   res.push_back(n-2);
   res.push_back(-((n-3)+(n-2)));
   return res;
}



int main(){
    int n = 3;
    vector<int> res = sumZero(n);

    for(auto x:res){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
