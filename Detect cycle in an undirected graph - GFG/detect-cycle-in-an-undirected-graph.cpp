// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    //so for undirected graph 
    bool dfs(vector<int> g[],vector<int>&vis,int cur,int par){
        vis[cur]=1;//make first vis[cur] as one
        for(auto x:g[cur]){
            //if the traversed node is par skip it
            if(x==par)continue;
            //if the traversed node is already visited then there is a cycle
            if(vis[x])return true;
            //else check if we can get true from somewhere
            else if(dfs(g,vis,x,cur))return true;
        }
        return false;
    }
    bool isCycle(int v, vector<int> g[]) {
        // Code here
        vector<int>vis(v);
        for(int i=0;i<v;i++){
            if(vis[i]==0){
                if(dfs(g,vis,i,-1))return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends