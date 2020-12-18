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
bool isValidBSTUtil(TreeNode* root,TreeNode* l,TreeNode* r){
    if(root == NULL) return true;
    /*The idea is that each node in subtree should be in range [l,r]
                5
               / \
              x   8 -->is in range [5,oo]
                /   \
in range [5,8] 4    9

    so maintain a pointer left and right, which helps to decide the range each subtree should be.
    if any value violates this condition then return false.
    */
    if(l != NULL && root->val <= l->val) return false;
    if(r != NULL && root->val >= r->val) return false;
    //new range is [oo,root]
    bool left = isValidBSTUtil(root->left,l,root);
    //new range is [root,oo]
    bool right = isValidBSTUtil(root->right,root,r);

    //both subtrees must be valid.
    return left&&right;
}
bool isValidBST(TreeNode* root) {
    return isValidBSTUtil(root,NULL,NULL);
}
int main(){
    TreeNode* root= new TreeNode(1);
    root->left = new TreeNode(1);
    //root->right = new TreeNode(1);
    //root->right->left = new TreeNode(6);
    //root->right->right = new TreeNode(9);

    bool res=  isValidBST(root);
    cout << res << " ";
    return 0;
}
