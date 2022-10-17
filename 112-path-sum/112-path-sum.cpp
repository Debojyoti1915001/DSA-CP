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
class Solution {
public:
    bool solve(TreeNode* root, int targetSum,int leafNodeSum){
        if(root==NULL)return false;
        leafNodeSum+=root->val;
        if(root->left==NULL&&root->right==NULL){
            if(targetSum==leafNodeSum)return true;
            else return false;
        }
        return solve(root->left,targetSum,leafNodeSum)|solve(root->right,targetSum,leafNodeSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum,0);
    }
};