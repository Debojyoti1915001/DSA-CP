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
// root][......left......][...right..]  ---pre
// [......left......][...right..][root]  ---post
class Solution {
public:
    unordered_map<int,int>m;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int len=postorder.size();
        for(int i=0;i<len;i++)m[postorder[i]]=i;
        return construct(preorder,postorder,0,len-1,0,len-1);
    }
    TreeNode*construct(vector<int>pre,vector<int>post,int a,int b,int c,int d){
        TreeNode*n=new TreeNode(pre[a]);
        if(a==b)return n;
        int t=pre[a+1];
        int idx=m[t];
        int len=idx-c+1;
        n->left=construct(pre,post,a+1,a+len,c,c+len-1);
        if(idx+1==d)return n;
        n->right=construct(pre,post,a+len+1,b,idx+1,d-1);
        return n;
    }
};