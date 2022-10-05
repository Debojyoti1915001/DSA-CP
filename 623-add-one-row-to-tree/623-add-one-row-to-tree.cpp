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
    TreeNode* addOneRow(TreeNode* root, int val, int depth,bool leftChild=true) {
        
        if(depth==1){
            if(!leftChild){
                return new TreeNode(val,NULL,root);
            }else{
                return new TreeNode(val,root,NULL);
            }
        }
        if(!root)return root;
        TreeNode*l=addOneRow(root->left,val,depth-1,true);
        TreeNode*r=addOneRow(root->right,val,depth-1,false);
        root->left=l;
        root->right=r;
        return root;
    }
};