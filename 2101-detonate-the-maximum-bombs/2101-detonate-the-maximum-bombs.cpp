class Solution {
public:
    void dfs(int cur,int &cnt,vector<int>&vis,vector<vector<int>>&adj){
        vis[cur]=1;
        cnt++;
        for(auto x:adj[cur]){
            if(!vis[x]){
                dfs(x,cnt,vis,adj);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            int x1=bombs[i][0],y1=bombs[i][1],r1=bombs[i][2];
            for(int j=0;j<n;j++){
                if(i!=j){
                    int x2=bombs[j][0],y2=bombs[j][1],r2=bombs[j][2];
                    long long dsq=(long long)(x1-x2)*(long long)(x1-x2)+(long long)(y1-y2)*(long long)(y1-y2);
                    long long p=r1;
                    if(dsq<=p*p){
                        adj[i].push_back(j);
                    }
                }
            }
        }
        vector<int>vis(n);
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            dfs(i,cnt,vis,adj);
            ans=max(ans,cnt);
            fill(vis.begin(),vis.end(),0);
        }
        return ans;
    }
};