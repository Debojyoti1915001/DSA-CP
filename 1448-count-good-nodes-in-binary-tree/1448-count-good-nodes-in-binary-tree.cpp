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
    // take every path
    // find the max in that path
    void solve(TreeNode* root,int  mx){
        if(!root)return;
        if(mx<=root->val){
            ans++;
        }
        solve(root->left,max(mx,root->val));
        solve(root->right,max(mx,root->val));
    }
    int goodNodes(TreeNode* root) {
        solve(root,INT_MIN);
        return ans;
    }
};