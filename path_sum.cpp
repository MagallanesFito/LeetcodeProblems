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
int currsum = 0;
bool hasPathSum(TreeNode* root, int sum) {
    if(currsum == sum){
        return true;
    }
    if(root->left !=NULL){
        currsum+=root->val;
        if(hasPathSum(root->left,sum)) return true;
        currsum-=root->val;
    }
    if(root->right !=NULL){
        currsum+=root->val;
        if(hasPathSum(root->right,sum)) return true;
        currsum-=root->val;
    }

    return false;
}

int main(){
    TreeNode* root = new TreeNode(1);
    cout << hasPathSum(root,0);
    return 0;
}
