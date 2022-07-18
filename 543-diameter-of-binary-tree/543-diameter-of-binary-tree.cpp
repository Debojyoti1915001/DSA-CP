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
    int res=INT_MIN;
    int solve(TreeNode* root){
        if(root==NULL)return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        int temp=max(l,r)+1;
        int ans=l+r+1;
        res=max(res,ans);
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return res-1;
    }
};