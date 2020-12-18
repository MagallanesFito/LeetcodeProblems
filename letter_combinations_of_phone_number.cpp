#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<string> res;
string curr = "";
map<char,vector<string>> letters;
void initMap(){
    letters['2'] = {"a","b","c"};
    letters['3'] = {"d","e","f"};
    letters['4'] = {"g","h","i"};
    letters['5'] = {"j","k","l"};
    letters['6'] = {"m","n","o"};
    letters['7'] = {"p","q","r","s"};
    letters['8'] = {"t","u","v"};
    letters['9'] = {"w","x","y","z"};
}
void letterCombinationsUtil(string digits,int pos){
    if(pos==digits.length()){
        res.push_back(curr);
        //cout << curr << endl;
        return;
    }

    for(auto x:letters[digits[pos]]){
        curr = curr + x;
        letterCombinationsUtil(digits,pos+1);
        curr = curr.substr(0,curr.length()-1);
    }
}
vector<string> letterCombinations(string digits) {
    initMap();
    if(digits.length() == 0) return res;
    letterCombinationsUtil(digits,0);
    return res;
}
int main(){
    initMap();
    string digits = "";
    vector<string> result = letterCombinations(digits);

    for(auto x:result) cout << x << endl;
    //letterCombinationsUtil(digits,0);
    return 0;
}




