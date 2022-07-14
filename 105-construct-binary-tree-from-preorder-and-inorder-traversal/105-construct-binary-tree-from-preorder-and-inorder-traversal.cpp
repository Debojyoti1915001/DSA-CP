class Solution {
public:
    int t=0;
    TreeNode* buildingTree(vector<int>pre, vector<int>in,int l,int r){
        if(l>r)return NULL;
        int ind=l;
        for(int i=l;i<=r;i++){
            if(pre[t]==in[i]){
                ind=i;
                break;
            }
        }
        t++;
        TreeNode* p=new TreeNode(in[ind]);
        p->left=buildingTree(pre,in,l,ind-1);
        p->right=buildingTree(pre,in,ind+1,r);
        return p;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildingTree(preorder,inorder,0,preorder.size()-1);
    }
};