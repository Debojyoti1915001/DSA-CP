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
    void flatten(TreeNode* root) {
        while(root!=NULL){
            if(root->left){
                TreeNode*nxt=root->right,*lt=root->left;
                root->right=lt;
                while(lt->right)lt=lt->right;
                root->left=NULL;
                lt->right=nxt;
            }
            root=root->right;
        }
    }
};