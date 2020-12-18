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

    //pick i as the root
    for(int i=start;i<=end_;i++){
        //generate all left subtrees with i as root;
        vector<TreeNode*> leftList = allTrees(start,i-1);
        //genrate all right subtrees with i as root;
        vector<TreeNode*> rightList = allTrees(i+1,end_);

        //all trees are a combination of every left with every right subtree
        for(int j=0;j<leftList.size();j++){
            TreeNode* left = leftList[j];
            for(int k=0;k<rightList.size();k++){
                TreeNode* right = rightList[k];
                //create tree with root i and left sub
                TreeNode* curr = new TreeNode(i);
                curr->left=  left;
                curr->right = right;
                res.push_back(curr);
            }
        }
        return res;
    }
}
int main(){

    return 0;
}

