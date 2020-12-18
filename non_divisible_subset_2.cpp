#include<iostream>
#include<vector>
#include<algorithm>

#define ios_ ios_base::sync_with_stdio(0);cin.tie(NULL);
using namespace std;

int module_freq[100];
int nonDivisibleSubset(int k, vector<int> s) {
   for(auto it=s.begin();it!=s.end();it++){
        module_freq[*it%k]++;
   }
   int ans = 0;
   //We can select only one 0, and one 2 if k is even
   ans += min(module_freq[0],1);
   if(k%2==0){
        ans += min(module_freq[k/2],1);
   }
   //max freq of i or its complement, cannot take both because i+k-i = k, this is divisible by k
   for(int i=1;i<k/2+1;i++){
    if(i!=k-i){
        ans+=max(module_freq[i],module_freq[k-i]);
    }
   }
   return ans;

}

int main(){
    ios_
    vector<int> t{1,7,2,4};
    int k = 3;
    int a = nonDivisibleSubset(k,t);
    cout << a << endl;
    return 0;
}
