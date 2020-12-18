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
TreeNode* buildTreeUtil(vector<int>& preorder,int p1,int p2,vector<int>& inorder,int i1,int i2) {
    if(i1>=i2 || p1>=p2) return NULL;
    //first element from preorder
    TreeNode *root = new TreeNode(preorder[p1]);
    //search first p1 preorder in inorder arr
    auto it = find(inorder.begin()+i1,inorder.begin()+i2,preorder[p1]);
    int diff = it - inorder.begin()-i1;
    root->left = buildTreeUtil(preorder,p1+1,p1+1+diff,inorder,i1,i1+diff);
    root->right = buildTreeUtil(preorder,p1+1+diff,p2,inorder,i1+diff+1,i2);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size() == 0) return NULL;
        int n = inorder.size();
        return buildTreeUtil(preorder,0,n,inorder,0,n);
}
int main(){

    return 0;
}
