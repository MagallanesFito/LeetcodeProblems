#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Approach1
/*class MapSum{
public:
    unordered_map<string,int> mymap;
    MapSum(){

    }
    void insert(string key, int val) {
        mymap[key] = val;
    }
    bool startsWith(string complete,string prefix){
        for(int i=0;i<prefix.length();i++){
            if(!(prefix[i] == complete[i])) return false;
        }
        return true;
    }
    int sum(string prefix) {
        int currSum = 0;
        for(auto kv:mymap){
            string currK = kv.first;
            int currV = kv.second;
            if(startsWith(currK,prefix)){
                currSum+=currV;
            }
        }
        return currSum;
    }
};*/


//using trie
class MapSum{
public:
    struct TrieNode{
        int score;
        unordered_map<char,TrieNode*> children;
        TrieNode() : score(0){}
    };
    TrieNode* root;
    MapSum(){
        root = new TrieNode();
    }
    void insert(string key, int val) {
        TrieNode* curr = root;
        for(auto ch:key){
            if(!curr->children[ch]){
                curr->children[ch] = new TrieNode();
            }
            curr->children[ch]->score += val;
            curr = curr->children[ch];
        }
    }
    int sum(string prefix) {
        TrieNode* curr= root;
        for(auto ch:prefix){
            curr = curr->children[ch];
            if(!curr) return 0;
        }
        return curr->score;
    }
};
int main(){
    unordered_map<string,int> mymap;
    mymap["hola"] = 1;
    return 0;
}
