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

 bool isSameTree(TreeNode* p, TreeNode* q) {
     if(q == NULL && p==NULL) return true;
     if(p == NULL || q == NULL) return false;
     if(p->val != q->val) return false;
     bool left= isSameTree(p->left,q->left);
     bool right= isSameTree(p->right,q->right);
     return left&&right;
}
int main(){
    return 0;
}



