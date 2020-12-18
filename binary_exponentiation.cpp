#include<iostream>
using namespace std;

//iterative
int power2(int a,int b){
    int res = 1;
    while(b>0){
        if(b%2==1) res = res*a;
        a = a*a;
        b = b/2;
    }
    return res;
}
//recursive way
int power(int a,int b){
    if(b==0) return 1;
    int tmp = power(a,b/2);
    int res = tmp*tmp;
    if(b%2==1) res = res*a;
    return res;
}
int main(){
    int a = 3;
    int b = 3;
    int res = power2(a,b);
    cout << res << endl;
    return 0;
}
