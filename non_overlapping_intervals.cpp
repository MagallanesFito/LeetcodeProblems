#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct compare{
    inline bool operator() (const vector<int>& v1,const vector<int>& v2){
        if(v1[1] < v2[1]) return true;
        return false;
    }
};
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if(intervals.size() == 0) return 0;
    int totalIntervals = intervals.size();
    sort(intervals.begin(),intervals.end(),compare());
    int nonoverlapping =1;
    int currFinish  = intervals[0][1];
    //cout << intervals[0][0] << " , " << intervals[0][1] << endl;
    for(int i = 1;i<intervals.size();i++){
        vector<int> cur = intervals[i];
        if(cur[0]>=currFinish){
            currFinish = cur[1];
            nonoverlapping++;
            //cout << cur[0] << " , " <<cur[1] << endl;

        }
    }
    return totalIntervals - nonoverlapping;
}
int main(){
    vector<vector<int>> inter = {};
    int a = eraseOverlapIntervals(inter);
    cout << a<< endl;
    return 0;
}

