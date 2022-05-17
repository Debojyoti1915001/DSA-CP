/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void dfs(TreeNode*& ans, TreeNode* c, TreeNode* t){
        if(!c)return;
        if(c->val==t->val){
            ans=c;
        }
        dfs(ans,c->left,t);
        dfs(ans,c->right,t);
        return;
    }
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* c, TreeNode* t) {
        TreeNode*ans=NULL;
        dfs(ans,c,t);
        return ans;
    }
};