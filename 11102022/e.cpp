#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

void addEdge(vector<pair<int, int> > adj[], int u, int v,
			int wt)
{
	adj[u].push_back(make_pair(v, wt));
	adj[v].push_back(make_pair(u, wt));
}

vector<int> shortestPath(vector<pair<int, int> > adj[], int V,
				int src)
{
	priority_queue<iPair, vector<iPair>, greater<iPair> >
		pq;

	vector<int> dist(V, INF);

	pq.push(make_pair(0, src));
	dist[src] = 0;

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		for (auto x : adj[u]) {
			int v = x.first;
			int weight = x.second;

			if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
    return dist;

}

// Driver program to test methods of graph class
int main()
{
    int d;
    cin>>d;
	int V ,m;
    cin>>V>>m;

	vector<iPair> adj[V];
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        addEdge(adj, x,y,z);
    }
    int mn=INT_MAX;
    int ans=0;
    for(int i=0;i<V;i++)
	{
        int cur=0;
        vector<int>dist=shortestPath(adj, V, i);
        for(int j=0;j<V;j++){
            if(i!=j&&dist[j]<=d)cur++;
        }
        if(mn>=cur){
            ans=i;
            mn=cur;
        }
    }
    cout<<ans+1<<endl;
	return 0;
}
