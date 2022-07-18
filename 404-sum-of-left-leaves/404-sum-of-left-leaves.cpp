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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(q.size()){
            int sz=q.size();
            while(sz--){
                TreeNode* t=q.front();
                q.pop();
                if(t->left){
                    q.push(t->left);
                    if(t->left->left==NULL&&t->left->right==NULL)ans+=t->left->val;   
                }
                if(t->right)q.push(t->right);
            }
        }
        return ans;
    }
};