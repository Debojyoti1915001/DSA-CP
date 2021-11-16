// https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/

We run Dijkstra algorithm starting from the nth node.

Let dist[u] be the distance from the u node to nth node.

Let cnt[u] be the number of restricted path from u node to nth node.

Each time we visit a new node u, we can update its cnt[u] to be the sum of cnt[v] 
where v is a neighbor of u and dist[v] is smaller than dist[u].

The answer is cnt[0].

class Solution {
    typedef pair<int,int>PII;
public:
    int countRestrictedPaths(int n, vector<vector<int>>& E) {
        long mod=1e9+7;
        vector<vector<pair<long,int>>>adj(n);
        for(auto &e:E){
            int u=e[0]-1,v=e[1]-1,w=e[2];
            adj[u].emplace_back(v,w);
            adj[v].emplace_back(u,w);
        }
        priority_queue<PII,vector<PII>,greater<PII>>pq;
        vector<long>dist(n,INT_MAX),cnt(n,0);
        dist[n-1]=0;
        cnt[n-1]=1;
        pq.emplace(0,n-1);
        while(pq.size()){
            auto [w,u]=pq.top();
            pq.pop();
            if(w>dist[u])continue;
            for(auto &[v,d]:adj[u]){
                if(dist[v]>w+d){
                    dist[v]=w+d;
                    pq.emplace(dist[v],v);
                }
                if(w>dist[v]){
                    cnt[u]=(cnt[u]+cnt[v])%mod;
                }
            }
        }
        for(auto x:dist)cout<<x<<" ";
        return cnt[0];
    }
};