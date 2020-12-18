#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Kadanes algorithm calculates maximum subarray sum in O(n)

int subarraySum(vector<int> a){
    int sum = 0;
    int best = 0;
    for(int i=0;i<a.size();i++){
        sum = max(a[i],a[i]+sum);
        best=  max(best,sum);
    }
    return best;
}
//supports the case when all values are negative
int subarraySumNegative(vector<int> a){
    int sum = a[0];
    int best = a[0];
    for(int i=1;i<a.size();i++){
        sum = max(a[i],a[i]+sum);
        best = max(sum,best);
    }
    return best;
}
int tableKadanes(vector<int> a){
    int dp[a.size()];
    dp[0] = 0;
    int sum = 0;
    for(int i=0;i<a.size();i++){
        sum = max(a[i],a[i]+sum);
        dp[i] = max(dp[i-1],sum);
    }
    return dp[a.size()-1];
}
void modifiedKadanes(vector<int> a){
    int sum=0;
    int best=0;
    int start=0;
    int end_=0;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        if(a[i]>sum){
            sum = a[i];
            start = i;
        }
        else{
            end_=i;
        }
        if(sum>best){
            best = sum;
        }
    }
    cout <<  start << " , " << end_ << "\n";
    cout<< "best: " << best << "\n";
}
int main(){
    vector<int> a = {1,2,3};
    int res = subarraySumNegative(a);
    cout << res << endl;
    return 0;
}
