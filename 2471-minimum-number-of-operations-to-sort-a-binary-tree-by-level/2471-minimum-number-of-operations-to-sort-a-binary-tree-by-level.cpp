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
    int changeRequired(vector<int>&v){
        
        int n=v.size();
        int ans=0;
        vector<pair<int,int>>A;
        for(int i=0;i<v.size();i++){
            A.push_back({v[i],i});
        }
        sort(A.begin(),A.end());
        vector<int>vis(n);
        for(int i=0;i<n;i++){
            if(vis[i]==0&&A[i].first!=i){
                int j=i;
                int cycle=0;
                while(!vis[j]){
                    cycle++;
                    vis[j]++;
                    j=A[j].second;
                }
                if(cycle>0){
                    ans+=cycle-1;
                }
            }
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        int ans=0;
        q.push(root);
        while(q.size()){
            int sz=q.size();
            vector<int>v;
            while(sz--){
                TreeNode*t=q.front();
                q.pop();
                v.push_back(t->val);
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            unordered_map<int,int>m;
            for(int i=0;i<v.size();i++){
                m[v[i]]=i;
            }
            ans+=changeRequired(v);
        }
        return ans;
    }
};