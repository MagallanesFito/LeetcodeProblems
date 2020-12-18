#include<iostream>
#include<vector>
using namespace std;

void reverseString(int l,vector<char> &s){
    if(l==s.size()/2) return;
    reverseString(l+1,s);
    int curr  = s.size()-1-l;
    //cout << l << " " << curr << endl;
    char tmp = s[l];
    s[l] = s[s.size()-1-l];
    s[s.size()-1-l]= tmp;
}
void reverseStringUtil(vector<char>& s){
    reverseString(0,s);
}
int main(){
    vector<char> s = {'h','e','l','l','o','a'};
    reverseStringUtil(s);
    for(int i=0;i<s.size();i++) cout << s[i] << " ";
    return 0;

}
