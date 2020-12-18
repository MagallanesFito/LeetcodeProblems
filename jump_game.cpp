#include<iostream>
#include<vector>
#include<map>
using namespace std;

//recursive solutioon, try all possible ways, gives TLE
bool canJump(vector<int> nums,int start){
    if(start == nums.size()-1) return true;
    if(nums[start] == 0) return false;

    for(int i=1;i<=nums[start];i++){
            //Make some DP to lower
        if(canJump(nums,start+i)) return true;
    }
    return false;
}

//Greedy strategy, works in linear time
bool canJump(vector<int>& nums) {
    int pos = 0;
    int canReach = 0 ;
    for(pos = 0;pos<=canReach;pos++){
        if(pos>=nums.size()-1) return true;
        canReach = max(canReach,pos+nums[pos]);
    }
    pos--;
    if(pos == nums.size()-1){
        //cout << pos << endl;
        return true;
    }
    if(nums[pos] == 0) return false;
    return true;
}
int main(){
    vector<int> num = {0,1};
    cout << canJump(num);
    return 0;
}
