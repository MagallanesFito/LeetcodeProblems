#include<iostream>
#include<vector>
using namespace std;

int freq[102];
vector<int> minSubsequence(vector<int>& nums) {
    int sa = 0;
    //make counting sort
    for(auto x:nums){
        sa+=x;
        freq[x]++;
    }
    int sk = 0;
    vector<int> res;
    //get first k elements that sum up > (total sum - currsum)
    for(int i=101;i>=1;i--){
        while(freq[i]>0){
          sk+=i;
          res.push_back(i);
          if(sk > (sa-sk)){
            return res;
          }
          freq[i]--;
        }
    }
    return res;
}
int main(){
   vector<int> a = {};
   vector<int> res = minSubsequence(a);
   for(auto x:res){
    cout << x << endl;
   }
    return 0;
}
