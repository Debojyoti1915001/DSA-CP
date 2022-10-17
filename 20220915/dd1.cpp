#include <bits/stdc++.h>
using namespace std;
 map<int,int>mp,mp1;
// Function for Depth first Search
void dfs(int s, vector<vector<int> > g,
         vector<int>& v)
{
    for (auto i : g[s]) {
 
        // If current vertex is
        // not visited yet
        if (!v[i]) {
            v[i] = 1;
 
            // Recursive call for
            // dfs function
            dfs(i, g, v);
        }
    }
}
 
// Function to find the out the minimum
// number of edges that must be removed
void deleteEdges(int n, int m, int a, int b,
                vector<vector<int> > edges)
{
    // Creating Adjacency Matrix
    vector<vector<int> > g(n, vector<int>());
    for (int i = 0; i < m; i++) {
        g[edges[i][0] - 1].push_back(edges[i][1] - 1);
        g[edges[i][1] - 1].push_back(edges[i][0] - 1);
    }
 
    // Vector for marking visited
    vector<int> v(n, 0);
    v[a - 1] = 1;
 
    // Calling dfs function
    dfs(a - 1, g, v);
 
    // Stores the final count
    int cnt = 0;
 
    for (int i = 0; i < n; i++) {
 
        // If current node can not
        // be visited from node A
        if (v[i] == 0)
            continue;
        for (int j = 0; j < g[i].size(); j++) {
 
            // If a node between current
            // node and node b exist
            if (g[i][j] == b - 1) {
				cout<<mp1[g[i][j]]<<" ";
            }
        }
    }
 
    // Return Answer
    return ;
}
 
// Driver Code
int main()
{
    int N ,M,A,B;
	cin>>N;
	for(int i=0;i<N;i++){
		int cur;
		cin>>cur;
		mp[cur]=i+1;
		mp1[i+1]=cur;
	}
	cin>>M;
    vector<vector<int> > edges;
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		edges.push_back({mp[a],mp[b]});
	}
	cin>>A>>B;
    deleteEdges(N, M, A, B, edges);
 
    return 0;
}