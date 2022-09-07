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
    string tree2str(TreeNode* root) {
        if(!root)return "";
        string ans=to_string(root->val);
        string l=tree2str(root->left);
        string r=tree2str(root->right);
        if(r.size()){
            ans+="("+l+")";
            ans+="("+r+")";
        }else if(l.size()){
            ans+="("+l+")";
        }
        return ans;
    }
};