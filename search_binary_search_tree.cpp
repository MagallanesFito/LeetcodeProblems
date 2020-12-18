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
TreeNode* searchBST(TreeNode* root,int val){
    if(root==NULL || root->val == val){
        return root;
    }
    if(root->val < val){
        return searchBST(root->right,val);
    }
    if(root->val > val){
        return searchBST(root->left,val);
    }
    //return root;

}
int main(){
    TreeNode* root = new TreeNode(4);
    root->left=  new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    TreeNode* found = searchBST(root,5);
    if(found == NULL){
        cout<< "NULL" << endl;
    }
    else{
        cout<< found->val << endl;
    }
    return 0;

}
