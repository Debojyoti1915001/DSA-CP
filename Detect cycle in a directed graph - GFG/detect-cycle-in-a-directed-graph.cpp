// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> g[],vector<int>&order,vector<int>&vis,int i){
        order[i]=1;
        vis[i]=1;
        for(auto &j:g[i]){
            if(!vis[j]){
                if(dfs(g,order,vis,j))return true;
            }else if(order[j])return true;
        }
        order[i]=0;
        return false;
    }
    bool isCyclic(int n, vector<int> g[]) {
        // code here
        vector<int>order(n),vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(g,vis,order,i))return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends