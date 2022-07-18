class Solution {
public:
    int t=0;
    map<int,int>mp;
    TreeNode* buildingTree(vector<int>pre, vector<int>in,int l,int r){
        if(l>r)return NULL;
        int ind=mp[pre[t]];
        t++;
        TreeNode* p=new TreeNode(in[ind]);
        p->left=buildingTree(pre,in,l,ind-1);
        p->right=buildingTree(pre,in,ind+1,r);
        return p;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<preorder.size();i++){
            mp[inorder[i]]=i;
        }
        return buildingTree(preorder,inorder,0,preorder.size()-1);
    }
};