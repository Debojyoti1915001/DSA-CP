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
    int solve(TreeNode* root,vector<int>&cnt){
        if(!root){
            return 0;
        }
        cnt[root->val]++;
        if(!root->left&&!root->right){
            int o=0;
            for(auto &j:cnt){
                if(j%2==1){
                    o++;
                }
            }
            if(o<=1){
                cnt[root->val]--;
                return 1;
            }
        }
        int cur=solve(root->left,cnt)+solve(root->right,cnt);
        cnt[root->val]--;
        return cur;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root)return 0;
        vector<int>cnt(10);
        return solve(root,cnt);
    }
};