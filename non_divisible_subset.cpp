#include<iostream>
#include<vector>
#include<algorithm>

#define ios_ ios_base::sync_with_stdio(0);cin.tie(NULL);
using namespace std;

int binary_search_(int pos,vector<int> modules,int k,vector<int> num_ceros){
    int lo = pos+1;
    int hi = modules.size()-1;
    while(lo<hi){
        int m = (lo+hi)/2;
        int curr_sum = modules[m]+modules[pos];

        if(curr_sum<k){
            lo = m+1;
        }
        else{
            hi = m;
        }
    }
    hi--;
    return (hi-pos+1)-(num_ceros[hi] - num_ceros[pos]);
}
vector<int> calculateNumCeros(vector<int> modules){
    vector<int> result;
    result.push_back(0);
    //[1]
    if(modules[0] == 0){
        result[0] = 1;
    }
    for(int i=1;i<modules.size();i++){
        int curr = 0;
        if(modules[i]==0){
            curr = 1;
        }
        else{
            curr = 0;
        }
        result.push_back(curr+result[i-1]);
    }
    return result;
}
int nonDivisibleSubset(int k, vector<int> s) {
    vector<int> modules;
    for(auto it = s.begin();it!=s.end();it++){
        modules.push_back(*it%k);
    }
    sort(modules.begin(),modules.end());
    int max_result = -1;
    vector<int> num_ceros = calculateNumCeros(modules);
    for(int i=0;i<modules.size()-1;i++){
        int actual_result = binary_search_(i,modules,k,num_ceros);
        if(actual_result>max_result){
            max_result = actual_result;
        }
    }
    return max_result;
}

int main(){
    ios_
    vector<int> t{19,10,12,24,25,22};
    int k = 3;
    int a = nonDivisibleSubset(k,t);
    cout << a << endl;
    return 0;
}
