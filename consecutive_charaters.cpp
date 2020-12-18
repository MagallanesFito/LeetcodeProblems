#include<iostream>
#include<vector>
#include<map>
using namespace std;


int maxPower(string s) {
    if(s.length() == 1) return 1;
    char cur = s[0];
    int maximum = 1;
    int maxGlobal = 0;
    for(int i=1;i<s.length();i++){
        if(s[i] == cur){
            maximum++;
        }
        else{
            cur = s[i];
            maximum = 1;
        }
        maxGlobal = max(maxGlobal,maximum);
    }
    //cout << cur << endl;
    return maxGlobal;
}
int main(){
    int ma = maxPower("tourist");
    cout << ma << endl;
    return 0;
}
