#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0),left(nullptr),right(nullptr){}
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right) val(x),left(left),right(right){}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root){
        root = new TreeNode(val);
        return root;
    }
    TreeNode* tmp = root;

    while(true){
        if(!tmp->left && !tmp->right){
            if(val < tmp->val){
                tmp->left = new TreeNode(val);
                return root;
            }
            else{
                tmp->right = new TreeNode(val);
                return root;
            }
        }
        else{
            if(val < tmp->val){
                if(!tmp->left){
                   tmp->left = new TreeNode(val);
                    return root;
                }
                 tmp = tmp->left;

            }
            else{
                if(!tmp->right){
                    tmp->right = new TreeNode(val);
                    return root;
                }
                tmp = tmp->right;
            }
        }
    }
    return root;
}
int main(){
    return 0;
}
