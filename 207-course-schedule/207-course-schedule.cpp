class Solution {
public:
    //detect cycle in directed graph
    vector<vector<int>>g;
    vector<int>vis;
    bool cycle=false;
    void isCyclic(int i){
        vis[i]=1;
        for(auto &j:g[i]){
           if(vis[j]==0)
               isCyclic(j);
            if(vis[j]==1){
                cycle=true;
            }
        }
        vis[i]=2;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        g.resize(n);
        vis.resize(n,0);
        for(auto &i:p){
            g[i[0]].push_back(i[1]);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0)isCyclic(i);
            if(cycle)return false;
        }
        return true;
    }
};