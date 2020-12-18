#include<iostream>
#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int target,int l,vector<int> nums){
    int r = nums.size();
    while(l<r){
        int m = l + (r-l)/2;
        if(nums[m] == target){
            return true;
        }
        if(nums[m]>target){
            r= m;
        }
        else{
            l = m+1;
        }
    }
    return false;
}
vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> res;
    if(nums.size() == 0 || nums.size() == 1) return res;
    sort(nums.begin(),nums.end());

    set<pair<int,pair<int,int>>> freq;
    for(int i=0;i<nums.size()-2;i++){
            int j = i+1;
        //for(int j=i+1;j<nums.size()-1;j++){
            int target = -(nums[i]+nums[j]);
            bool found = binarySearch(target,j+1,nums);
            if(found){
                if(!freq.count({nums[i],{nums[j],target}})){
                    //vector<int> curr = {nums[i],nums[j],target};
                    cout<< nums[i] << " " << nums[j] << " " << target << endl;
                    freq.insert({nums[i],{nums[j],target}});
                    //res.push_back(curr);
                }

            }
        //}
    }
    return res;
}
int main(){
    //vector<int> t = {-1,0,1,2,-1,-4};

    //threeSum(t);
    for(int i=0;i<5;++i){
        cout << i << endl;
    }

    return 0;
}
