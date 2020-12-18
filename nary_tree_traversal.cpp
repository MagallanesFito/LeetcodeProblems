#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
vector<int> res;
vector<int> preorden(Node* root){
    if(root != NULL){
        res.push_back(root->val);
        for(int i=0;i<root->children.size();i++){
            preorden(root->children[i]);
        }
    }
    return res;
}
int main(){

    return 0;
}

