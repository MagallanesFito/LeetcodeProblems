
#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
vector<int> path;
vector<string> paths;
void appendToPaths(vector<int> pa){
   string nums = "0123456789";
   string curr="";
   for(int i=0;i<pa.size();i++){
      curr+=nums[pa[i]];
      if(i<pa.size()-1){
        curr+="->";
      }
   }
   //return curr;
   paths.push_back(curr);
}
void binaryTreePathsUtil(TreeNode* root){
    //cout << " w" << endl;
    if(!root || (!root->left && !root->right)){
        path.push_back(root->val);
        appendToPaths(path);
        //cout << converted << endl;
        //cout << " w" << endl;
        return;
    }
    if(root->left){
        path.push_back(root->val);
        binaryTreePathsUtil(root->left);
        path.pop_back();
    }

    if(root->right){
        path.push_back(root->val);
        binaryTreePathsUtil(root->right);
        path.pop_back();
    }
    path.pop_back();
    return;
}
vector<string> binaryTreePaths(TreeNode* root) {
        binaryTreePathsUtil(root);
        return paths;
}
int main(){
    TreeNode* root  = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    vector<string> m = binaryTreePaths(root);
    for(auto e:m) cout << e << endl;
    return 0;
}
