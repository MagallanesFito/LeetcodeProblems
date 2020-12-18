#include<iostream>
using namespace std;

/*as C(n,k) = [n(n-1)(n-2)...(n-k+1)(n-k)...1]/[(n-k)(n-k-1)...1][k(k-1)(k-2)...1]
simplifying (n-k)! : C(n,k) = n(n-1)..(n-k+1)/k!

Also:
C(n,k) = C(n,n-k), we can substitute k by n-k in case k is greater
*/
int binomialCoeff(int n,int k){
    if(k > n-k){
        k = n-k;
    }
    int res = 1;
    for(int i=0;i<k;i++){
        //calculate n(n-1)...(n-k+1)
        res = res * (n-i);
        //calculate 1(2)(3)...(k)
        res = res/(i+1);
    }
    return res;
}
int main(){
    int res = binomialCoeff(3,2);
    cout << res;
    return 0;
}
