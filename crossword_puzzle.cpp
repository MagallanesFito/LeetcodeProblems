#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> separateWords(string words){
    vector<string> vwords;
    string curr= "";
    for(int i=0;i<words.length();i++){
        if(words[i] != ';'){
            curr+=words[i];
        }
        else{
            vwords.push_back(curr);
            curr = "";
            continue;S
        }
    }
    vwords.push_back(curr);
    return vwords;
}
vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    vector<string> res;
    vector<string> vwords = separateWords(words);


    return res;
}
int main(){
    string words = "LONDON;DELHI;ICELAND;ANKARA";
    vector<string> a;
    vector<string> b = crosswordPuzzle(a,words);
    for(auto x:b) cout << x << " ";
    cout << endl;
    return 0;
}



