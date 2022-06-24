// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//finding the transpose of the graph
	void transpose(int V,vector<int>adj[],vector<int>transpose_adj[]){
	    for(int u=0;u<V;u++){
	        for(auto v:adj[u])transpose_adj[v].push_back(u);
	    }
	}
	stack<int>s;
	void dfs(vector<int>adj[],vector<bool>&vis,int u){
	    vis[u]=true;
	    for(auto v:adj[u]){
	        if(vis[v]==0)dfs(adj,vis,v);
	    }
	}
	//this function basically finds the topological sort 
	void fillorder(vector<int>adj[],vector<bool>&vis,int u){
	    vis[u]=true;
	    for(auto v:adj[u]){
	        if(vis[v]==0)fillorder(adj,vis,v);
	    }
	    s.push(u);
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
         vector<bool>visited(V,false);
        
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                fillorder(adj, visited, i);
        
        vector<int> transpose_adj[V];
        transpose(V, adj, transpose_adj);
    
        for (int i = 0; i < V; i++)
            visited[i] = false;
    
        int ans = 0;
        
        while (!s.empty()) 
        {
            int temp = s.top();
            s.pop();
            
            if (!visited[temp]) {
                //if it is not visited then visit all the ele it can reach
                dfs(transpose_adj, visited, temp);
                ans++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends