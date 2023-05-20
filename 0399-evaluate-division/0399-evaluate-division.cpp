class Solution {
public:
    //to store the adjacency list
    unordered_map<string,vector<pair<string,double>>>adj;
    //to keep a tract of visited nodes
    unordered_map<string,bool>vis;
    double cur;
    bool dfs(string s,string e,double product){
        if(s==e&&adj.find(s)!=adj.end()){
            cur=product;
            return true;
        }
        bool tempAns=false;
        vis[s]=true;
        for(int i=0;i<adj[s].size();i++){
            if(!vis[adj[s][i].first]){
                tempAns=dfs(adj[s][i].first,e,product*adj[s][i].second);
                if(tempAns)break;
            }
        }
        vis[s]=false;
        return tempAns;
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) {
        int n=eq.size(),m=q.size();
        vector<double>ans(m);
        for(int i=0;i<n;i++){
            adj[eq[i][0]].push_back({eq[i][1],val[i]});
            adj[eq[i][1]].push_back({eq[i][0],1/val[i]});
            vis[eq[i][0]]=false;
            vis[eq[i][1]]=false;
        }
        
        for(int i=0;i<m;i++){
            cur=1;
            bool pathFound=dfs(q[i][0],q[i][1],1);
            if(pathFound)ans[i]=cur;
            else ans[i]=-1;
        }
        return ans;
    }
};