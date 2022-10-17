class Solution {
public:
    //detect cycle in directed graph
    vector<vector<int>>g;
    vector<int>vis,order;
    bool isCyclic(int i){
        vis[i]=1;
        order[i]=1;
        for(auto &j:g[i]){
           if(!vis[j]){
               if(isCyclic(j))return true;
           }
           else if(order[j]){
               return true;
           }
        }
        order[i]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        g.resize(n+1);
        vis.resize(n+1,0);
        order.resize(n+1,0);
        for(auto &i:p){
            g[i[0]].push_back(i[1]);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0)
                if(isCyclic(i))return false;
        }
        return true;
    }
};