#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


string getPermutation(int n, int k) {
   vector<string> nums = {"1","2","3","4","5","6","7","8","9"};
    int k_ = 0;
    string res = "";
    do{
        if(k_ == k) break;
        res = "";
        for(int i=0;i<n;i++) res+=nums[i];
        k_++;

    }while(next_permutation(nums.begin(),nums.begin()+n));
    return res;
}
int main(){
    string res = getPermutation(4,9);
    cout << res << endl;
    return 0;
}

