#include<iostream>
using namespace std;

struct node{
    bool isWord;
    node* children[26];
};
class Trie{
public:
    node* create(){
        node* x = new node();
        for(int i=0;i<26;i++){
            x->children[i] = NULL;
        }
        x->isWord = false;
        return x;
    }
    node* root;
    Trie(){
        root = create();
    }
    void insert(string word){
        node* curr = root;
        for(int i=0;i<word.length();i++){
            int index = word[i] - 'a';
            if(curr->children[index] == NULL){
                curr->children[index] = create();
            }
            curr = curr->children[index];
        }
        curr->isWord = true;
    }
    bool search(string word){
        node* curr = root;
        for(int i=0;i<word.length();i++){
            int index = word[i] - 'a';
            if(curr->children[index] == NULL){
                return false;
            }
            curr = curr->children[index];
        }
        if(curr->isWord == false){
            return false;
        }
        return true;
    }
    bool startsWith(string prefix){
        node* curr = root;
        for(int i=0;i<prefix.length();i++){
            int index = prefix[i] - 'a';
            if(curr->children[index] == NULL) return false;
            curr= curr->children[index];
        }
        return true;
    }
};
int main(){
    return 0;
}
