#include<iostream>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL) return NULL;
    if(root->val == p->val || root->val == q->val){
        return root;
    }

    TreeNode* leftSearch = lowestCommonAncestor(root->left,p,q);
    TreeNode* rightSearch = lowestCommonAncestor(root->right,p,q);

    if(leftSearch == NULL) return rightSearch;
    if(rightSearch == NULL) return leftSearch;
    return root;
}
int main(){

    return 0;
}
