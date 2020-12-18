#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int sumDivisor(int divisor,vector<int> nums){
    int sum=0;
    for(auto x:nums){
        double c = (1.0*x)/(1.0*divisor);
        int c_ = (int)ceil(c);
        sum+=c_;
    }
    return sum;
}
int smallestDivisor(vector<int>& nums, int threshold) {
    int l = 1;
    int r = 3;
    for(auto x:nums) if(x>r) r = x;
    //cout << r << endl;
    while(l<r){
        int m = l + (r-l)/2;
        if(sumDivisor(m,nums) <= threshold){
            r = m;
        }
        else{
            l = m+1;
        }
    }
    return l;
}
int main(){
    vector<int> nums = {1,2,3};
    int res = smallestDivisor(nums,6);
    cout << res << endl;
    return 0;
}
