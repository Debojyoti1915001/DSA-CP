// https://leetcode.com/problems/find-mode-in-binary-search-tree/

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
    vector<int>res;
    int maxFreq=0,curFreq=0,prev=INT_MIN;
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }
    void inorder(TreeNode* root){
        if(root==NULL)return;
        inorder(root->left);
        if(prev==root->val){
            curFreq++;
        }else{
            curFreq=1;
        }
        if(maxFreq==curFreq){
            res.push_back(root->val);
        }else if(maxFreq<curFreq){
            res.clear();
            res.push_back(root->val);
            maxFreq=curFreq;
        }
        prev=root->val;
        inorder(root->right);
    }
};