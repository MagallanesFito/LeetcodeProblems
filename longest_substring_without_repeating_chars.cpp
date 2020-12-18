#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {
    map<char,bool> freq;
    int sum = 0 ;
    int best = 0;
    for(int i=0;i<s.length();i++){
        //int pos = t[i] - 'a';

        if(freq.find(s[i]) == freq.end()){
            freq.insert({s[i],true});
            sum++;
        }
        else{
            freq.clear();
            //clearFreq();
            sum = 1;
            freq.insert({s[i],true});
        }
        //for(int i=0;i<tn;i++) cout << freq[i] << " ";
        //cout << endl;
        best = max(best,sum);
    }
    return best;
}
int main(){
    string t = "pwwkew";
    int res = lengthOfLongestSubstring(t);
    cout << res << endl;
    return 0;
}
