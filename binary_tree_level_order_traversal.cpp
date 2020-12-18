#include<iostream>
#include<queue>
#include<vector>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct levelNode{
    TreeNode* node;
    int level;
    levelNode(int levelx,TreeNode* nodex): level(levelx), node(nodex) {}
};
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<levelNode> q;
    if(root == NULL){
        return res;
    }
    levelNode first(0,root);
    q.push(first);
    vector<int> curr;
    //curr.push_back(root->val);
    //res.push_back(curr);

    while(!q.empty()){
        levelNode actual = q.front();
        q.pop();
        if(actual.level>=res.size()){
            vector<int> vlevel = {actual.node->val};
            res.push_back(vlevel);
        }
        else{
            res[actual.level].push_back(actual.node->val);
        }

        //enqueue children
        levelNode actualLeft(actual.level+1,actual.node->left);
        q.push(actualLeft);
        levelNode actualRight(actual.level+1,actual.node->right);
        q.push(actualRight);

    }
    reverse(res.begin(),res.end());
    return res;
}
int main(){
    vector<vector<int>> res=  levelOrder();
    return 0;
}
