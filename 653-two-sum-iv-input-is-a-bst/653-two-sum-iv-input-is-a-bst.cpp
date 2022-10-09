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
    vector<int>v;
    void fun(TreeNode* root){
        if(root==NULL)return;
        fun(root->left);
        v.push_back(root->val);
        fun(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
       fun(root); 
        int l=0,r=v.size()-1;
        while(l<r){
            int sum=v[l]+v[r];
            if(sum==k)return true;
            if(sum>k)r--;
            else l++;
        }
        return false;
    }
};