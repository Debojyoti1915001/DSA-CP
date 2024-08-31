class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>>g(n);
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back({edges[i][1],succProb[i]});
            g[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double>prb(n);
        prb[start]=1;
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start});
        while(!pq.empty()){
            auto [p,t]=pq.top();
            pq.pop();
            for(auto x:g[t]){
                if(prb[x.first]<prb[t]*x.second){
                    prb[x.first]=prb[t]*x.second;
                    pq.push({prb[x.first],x.first});
                }
            }
        }
        return prb[end];
    }
};