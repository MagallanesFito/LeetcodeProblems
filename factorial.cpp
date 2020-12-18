#include<iostream>
#include<vector>

using namespace std;
int factorial(int n){
    if(n==1) return 1;
    int cur = factorial(n-1);
    int res = n*cur;
    return res;
}
int main(){
    int a = factorial(5);
    cout << a << endl;
    return 0;
}
