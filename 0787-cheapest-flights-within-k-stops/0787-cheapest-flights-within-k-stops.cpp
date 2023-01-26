class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        //Using dijkstra algo

        //create a adj list for directed weighted graph
        vector<pair<int,int>> adj[n];
        for(auto it : flights)
           adj[it[0]].push_back({it[1],it[2]});

        //create a dist array 
        vector<int> dist(n,1e9);

        //Create a queue for stops,node and cost(dist) 
        queue<pair<int,pair<int,int>>> q;

        //Push intial config 
        q.push({0,{src,0}});

        //src dist is always 0
        dist[src] = 0;

        //traverse into queue
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            //Take these values from queue
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
            //If stops greater k then skip 
            if(stops>k)
               continue;

            //go to neighbour
            for(auto itr : adj[node])
            {
                int adjNode = itr.first;
                int adjCost = itr.second;

                if(cost + adjCost < dist[adjNode] && stops<=k)
                {
                    dist[adjNode] = cost + adjCost;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }   

        }

        //dist for dst
        if(dist[dst]==1e9)
           return -1;

        return dist[dst];   
    }
};