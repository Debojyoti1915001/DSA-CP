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
    void solve(TreeNode* root,vector<int>&cnt){
        if(!root){
            return;
        }
        cnt[root->val]++;
        if(!root->left&&!root->right){
            int o=0;
            for(auto &j:cnt){
                if(j%2==1){
                    o++;
                }
            }
            if(o<=1)ans++;
        }
        solve(root->left,cnt);
        solve(root->right,cnt);
        cnt[root->val]--;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root)return 0;
        vector<int>cnt(10);
        solve(root,cnt);
        return ans;
    }
};