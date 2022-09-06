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
    bool solve(TreeNode** root){
        if(*root==NULL)return false;
        bool l=solve(&(*root)->left);
        bool r=solve(&(*root)->right);
        if((*root)->val==1)return true;
        if(!l&&!r){
            *root=NULL;
            return false;
        }
        return true;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool get=solve(&root);
        return root;
    }
};