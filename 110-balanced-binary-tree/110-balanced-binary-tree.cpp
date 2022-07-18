/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     int height(TreeNode* root){
//         if(root==NULL)return 0;
//         return max(height(root->left)+1,height(root->right)+1);
//     }
//     bool isBalanced(TreeNode* root) {
//         if(root==NULL)return true;
//         int l=height(root->left);
//         int r=height(root->right);
//         if(abs(l-r)<=1&&isBalanced(root->left)&&isBalanced(root->right))return true;
//         return false;
//     }
// };
class Solution {
public:
    bool ans;
    int checkBalance(TreeNode* root){
        if(!root)
            return 0;
        if(!ans) // if Answer is already False then return it.
            return 0;
        int leftSubTree = checkBalance(root->left);
        int rightSubTree = checkBalance(root->right);
        if(abs(leftSubTree-rightSubTree) > 1){
            ans = false;
        }
        return 1 + max(leftSubTree, rightSubTree);
    }
    bool isBalanced(TreeNode* root){
        ans = true;
        int temp = checkBalance(root);
        return ans;
    }
};