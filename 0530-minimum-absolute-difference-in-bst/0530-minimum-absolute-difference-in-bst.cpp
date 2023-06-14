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
    vector<int> v;
    void solve(TreeNode* root,vector<int> &v){
        if(root==NULL)return;
        solve(root->left,v);
        v.push_back(root->val);
        solve(root->right,v);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        solve(root,v);
        int ans=abs(v[0]-v[1]);
        for(int i=1;i<v.size();i++){
            ans=min(ans,abs(v[i]-v[i-1]));
        }
        return ans;
    }
};