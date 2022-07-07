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
    vector<TreeNode*> tree;//contains all the nodes with val equal to sub's root node
    void find(TreeNode*root,TreeNode*sub){
        if(root==NULL)return;
        if(root->val==sub->val){
            tree.push_back(root);
        }
        find(root->left,sub);
        find(root->right,sub);
    }
    bool check(TreeNode* p, TreeNode* q){
        if((p==NULL&&q!=NULL)||(p!=NULL&&q==NULL))return false;
        if(p==NULL&&q==NULL)return true;
        if(p->val!=q->val)return false;
        bool l=check(p->left,q->left);
        bool r=check(p->right,q->right);
        return l&&r;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL||subRoot==NULL)return false;
        find(root,subRoot);
        if(tree.size()==0)return false;
        for(int i=0;i<tree.size();i++){
            if(check(tree[i],subRoot))return true;
        }
        return false;
    }
};