#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//no restrictions
bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]) return true;
        }
        return false;
}
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> hashT;

    if(nums.size() == 0 || nums.size() == 1) return false;
    //build window with k elements
    for(int i=0;i<=k;i++){
        //avoid sliding window get ouside array boundaries.
        if(i<nums.size()){
            if(hashT.find(nums[i]) != hashT.end()){
            //cout << nums[i] << endl;
            return true;
        }
        hashT.insert(nums[i]);
        }
    }
    for(int i=k+1;i<nums.size();i++){
        hashT.erase(nums[i-k-1]);
        if(hashT.find(nums[i]) != hashT.end()){
            //cout << " hee" << endl;
            return true;
        }
        hashT.insert(nums[i]);
    }
    return false;
}
void printV(vector<int> nums){
    for(auto x: nums) cout << x << " ";
    cout << endl;
}

long calculateAbsDiff(multiset<long> tree){
    multiset<long>::iterator it;
    vector<long> sums;
    long diff;
    long mindiff=(1<<30)+1;
    for(it = tree.begin();it!=tree.end();it++){
        if(sums.size() < 2){
            sums.push_back(*it);
        }
        else{
            diff = sums[1]-sums[0];
            mindiff = min(mindiff,diff);
            //cout << mindiff << endl;
            sums.erase(sums.begin());
            sums.push_back(*it);
        }
        //cout<< *it << endl;
    }
    diff = sums[1]-sums[0];
    mindiff = min(mindiff,diff);
    //cout << mindiff << endl;
    return mindiff;
}
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    multiset<long> tree;

    for(int i=0;i<=k;i++){
        if(i<nums.size()){
            tree.insert(nums[i]);
        }
    }
    long minAbsDiff = calculateAbsDiff(tree);
    //cout << minAbsDiff << endl;
    if(minAbsDiff <=t)return true;
    for(int i=k+1;i<nums.size();i++){
        minAbsDiff = calculateAbsDiff(tree);
        if(minAbsDiff <=t)return true;
        multiset<long>::iterator itr = tree.find(nums[i-k-1]);
        tree.erase(itr);
        tree.insert(nums[i]);
    }
    return false;
}
int main(){
    vector<int> a = {1,2,3,1};
    int k = 3;
    int t = 0;
    cout << containsNearbyAlmostDuplicate(a,k,t);
    return 0;
}
