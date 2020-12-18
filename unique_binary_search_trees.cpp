#include<iostream>
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
vector<TreeNode*> allTrees(int start,int end_){
    vector<TreeNode*> res;
    if(start>end_){
        res.push_back(NULL);
        return res;
    }
    for(int i=start;i<=end_;i++){
        vector<TreeNode*> leftList = allTrees(start,i-1);
        vector<TreeNode*> rightList = allTrees(i+1,end_);
        for(int j=0;j<leftList.size();j++){
            TreeNode* left =leftList[j];
            for(int k=0;k<rightList.size();k++){
                TreeNode* right = rightList[k];
                TreeNode* curr = new TreeNode(i);
                curr->left = left;
                curr->right = right;
                res.push_back(curr);
            }
        }
    }
    return res;
}
vector<TreeNode*> generateTrees(int n){
    vector<TreeNode*> res;
    if(n==0){
        return res;
    }
    return allTrees(1,n);
}
int main(){
    vector<TreeNode*> res = generateTrees(3);

    return 0;
}
