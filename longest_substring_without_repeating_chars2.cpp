#include<iostream>
using namespace std;

int freq[129];
    //limpiar frequencias,,,, toma O(1)
    void clearFreqs(){
        for(int i=0;i<129;i++) freq[i] = 0;
    }
    bool repeated(){
        for(int i=0;i<129;i++){
            if(freq[i]>1) return true;
        }
        return false;
    }
    bool goodSubstr(int m,string s){
        clearFreqs();
        //calculate first window
        //bool repeated = false;
        for(int i=0;i<m;i++){
            unsigned char indx = s[i];
            freq[indx]++;
        }
        if(!repeated())return true;
        //slide window
        for(int i=1;i<=s.length()-m;i++){
            //remove i-1 th char
            int indx = s[i-1];
            freq[indx]--;
            //add i+m th char
            indx = s[i+m-1];
            freq[indx]++;
            if(!repeated()) return true;

        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        int l = 1;
        int r = s.length();

        //binary search
        while(l<r){
            int m = (l+r)/2;
            if(!goodSubstr(m,s)){
                r = m;
            }
            else{
                l = m+1;
            }
        }
        if(goodSubstr(l+1,s)) return l+1;
        if(goodSubstr(l,s)) return l;
        if(goodSubstr(l-1,s)) return l-1;
        return l;
    }

    int main(){
        string a = "abcabcbb";
        //cout << lengthOfLongestSubstring(a) << endl;
        unsigned char b= '«';
        cout << b << endl;
        return 0;
    }
