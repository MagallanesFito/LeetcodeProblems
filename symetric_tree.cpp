#include<iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool isSymetricUtil(TreeNode* root1,TreeNode* root2){
    if(root1==NULL && root2==NULL) return true;

    if(root1!=NULL && root2!=NULL && root1->val == root2->val){
        bool symLeft = isSymetricUtil(root1->left,root2->right);
        bool symRight = isSymetricUtil(root1->right,root2->left);
        return symLeft&&symRight;
    }
    return false;
}
bool isSymmetric(TreeNode* root) {
   return isSymetricUtil(root,root);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    return 0;
}
