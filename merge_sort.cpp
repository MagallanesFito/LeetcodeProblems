#include<iostream>
#include<vector>
using namespace std;

vector<int> mergeArrays(vector<int> left,vector<int> right){
    vector<int> res;
    int pleft = 0;
    int pright = 0;
    int pres = 0;

    while(pleft<left.size() && pright < right.size()){
        if(right[pright] >= left[pleft]){
            res.push_back(left[pleft++]);
        }
        else{
            res.push_back(right[pright++]);
        }
    }
    while(pleft<left.size()){
        res.push_back(left[pleft++]);
    }
    while(pright<right.size()){
        res.push_back(right[pright++]);
    }
    return res;
}
vector<int> mergeSort(vector<int> input,int l,int r){
    if(l>=r){
        vector<int> res;
        res.push_back(input[l]);
        return res;
    }
    int m = l + (r-l)/2;
    vector<int> left = mergeSort(input,l,m);
    vector<int> right = mergeSort(input,m+1,r);
    vector<int> result = mergeArrays(left,right);
    return result;
}
int main(){
    vector<int> a = {3,1,4,0,-1,5};
    vector<int> res = mergeSort(a,0,a.size()-1);

    for(auto x:res){
        cout << x << " ";
    }
    return 0;
}
