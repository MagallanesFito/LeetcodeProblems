#include<iostream>
#include<vector>
using namespace std;


vector<string> res;
//generate all permutations with
int l = 0;
int r = 0;
string cur = "";

void generateParenthesisUtil(int n){
    if(l == n && r==n){
        res.push_back(cur);
        //cout << cur << endl;
        return;
    }
    if(l>r && r<n){
        cur = cur+")";
        r++;
        generateParenthesisUtil(n);
        r--;
        cur = cur.substr(0,cur.length()-1);
    }
    if(l<n){
        l++;
        cur = cur + "(";
        generateParenthesisUtil(n);
        l--;
        cur = cur.substr(0,cur.length()-1);
    }
}
vector<string> generateParenthesis(int n) {
    generateParenthesisUtil(n);
    return res;
}
int main(){
    vector<string> result = generateParenthesis(1);
    for(auto x:result) cout << x << endl;
    return 0;
}



