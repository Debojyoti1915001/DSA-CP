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
    unordered_map<int,vector<int>>g;
    void buildGraph(TreeNode* root){
        if(!root)return;
        if(root->left){
            g[root->val].push_back(root->left->val);
            g[root->left->val].push_back(root->val);
        }
        if(root->right){
            g[root->val].push_back(root->right->val);
            g[root->right->val].push_back(root->val);
        }
        buildGraph(root->left);
        buildGraph(root->right);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* t, int k) {
        buildGraph(root);
        queue<int>q;
        unordered_map<int,int>vis;
        q.push(t->val);
        while(q.size()&&k--){
            int sz=q.size();
            while(sz--){
                int t=q.front();
                vis[t]=1;
                q.pop();
                for(auto i:g[t]){
                    if(!vis[i]){
                        vis[i]=1;
                        q.push(i);
                        // cout<<i<<" ";
                    }
                }
            }
            // cout<<endl;
        }
        vector<int>ans;
        while(q.size()){
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};