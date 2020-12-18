#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
void traverse(TreeNode* root,vector<string>&paths,string str){
    if(!root->left && !root->right){
        paths.push_back(str+to_string(root->val));
        return;
    }
    str+=to_string(root->val) + "->";
    if(root->left) traverse(root->left,paths,str);
    if(root->right) traverse(root->right,paths,str);
}
vector<string> binaryTreePaths(TreeNode* root) {
    if(!root) return {};
    vector<string> paths;
    string path = "";
    traverse(root,paths,path);
    return paths;
}
int main(){
    vector<int> a = {1,2,3,1};
    int k = 3;
    int t = 0;
    cout << containsNearbyAlmostDuplicate(a,k,t);
    return 0;
}
