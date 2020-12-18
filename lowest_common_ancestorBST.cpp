#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
bool findNode(TreeNode* root,TreeNode* p){
    if(!root) return false;
    if(root->val == p->val) return true;
    if(root->val < p->val){
        return findNode(root->right,p);
    }
    if(root->val > p->val){
        return findNode(root->left,p);
    }
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    bool findLeft = findNode(root->left,p) || findNode(root->left,q);
    bool findRight = findNode(root->right,p) || findNode(root->right,q);

    if(findLeft && findRight) return root;
    if(!findLeft && findRight) return lowestCommonAncestor(root->right,p,q);
    if(findLeft && !findRight) return lowestCommonAncestor(root->left,p,q);

}
int main(){

    return 0;
}
