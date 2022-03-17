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
    long long int total=0,ans=0;
    void check(TreeNode* root){
        if(root==NULL)return;
        ans=max(ans,(total-root->val)*(root->val));
        check(root->left);
        check(root->right);
    }
    int reform(TreeNode* root){
        if(root==NULL)return 0;
        if(root->left==NULL&&root->right==NULL){
            total+=root->val;
            return root->val;
        }
        int l=reform(root->left);
        int r=reform(root->right);
        total+=root->val;
        root->val=l+r+root->val;
        return root->val;
    }
    int maxProduct(TreeNode* root) {
        reform(root);
        check(root);
        int mod=1e9+7;
        return ans%mod;
    }
};