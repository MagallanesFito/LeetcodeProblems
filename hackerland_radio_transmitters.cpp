#include<iostream>
#include <utility>
#include<algorithm>
#include<vector>
using namespace std;

int cur_start;
int cur_end;
int tabla[100001];
bool sort_by_sec(pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b){
    return a.second.second<b.second.second;
}
int hackerlandRadioTransmitters(vector<int> x, int k) {
    int res = 0;
    int cur_max;
    cur_max = x[0];
    for(int i=0;i<x.size();i++){
        if(x[i] > cur_max){
            cur_max = x[i];
        }
    }
    //id,<s,e>
    vector<pair<int,pair<int,int>>> activities;

    for(int i=0;i<x.size();i++){
        cur_start = x[i]-k;
        cur_end = x[i] + k;

        if(cur_start<=0){
            cur_start+=k;
        }
        if(cur_end>cur_max){
            cur_end-=k;
        }
        activities.push_back(make_pair(x[i],make_pair(cur_start,cur_end)));
    }
    sort(activities.begin(),activities.end(),sort_by_sec);
    vector<pair<int,int>> result;
    int prev = -10000;
    for(int i=0;i<activities.size();i++){
        //cout<<activities[i].first<<activities[i].second << endl;
        if(activities[i].second.first > prev){
            result.push_back(make_pair(activities[i].second.first,activities[i].second.second));
            prev = activities[i].second.second;
            //tabla[activities[i].first] = i+1;
            //cout << "si " << activities[i].first << endl;
        }
    }
    for(int i=0;i<result.size();i++){
        int l = result[i].first;

        int r = result[i].second;
        for(int j=l;j<=r;j++){
            tabla[j] = 1;
        }
    }

    res = result.size();
    //cout << "resu" << res << endl;
    for(int i=0;i<cur_max;i++){
        //cout << i <<
        if(tabla[i] == 0) res++;
    }
    return res;
}
int main(){
    vector<int> t = {7,2,4,6,5,9,12,11};
    cout <<hackerlandRadioTransmitters(t,2) << endl;
    return 0;
}
