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
    int ans=0;
    int solve(TreeNode* root){
        if(!root)return 0;
        if(root->left==NULL&&root->right==NULL){
            ans+=abs(root->val-1);
            return root->val-1; 
        }
        //nicha jitna hai ek chorke sab return kardo
        int r=0,l=0,cur=root->val;
        if(root->left!=NULL)l=solve(root->left);
        if(root->right!=NULL)r=solve(root->right);
        ans+=abs(cur+l+r-1);
        return cur+l+r-1;
    }
    int distributeCoins(TreeNode* root) {
        solve(root);
        return ans;
    }
};