class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int> indeg(n,0);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            int from=i;
            int to=edges[i];
            if(to!=-1)
               indeg[to]++;
        }
       
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)
            {
                q.push(i);
                vis[i]=1;
            }
            
        }
        while(q.empty()==false){
            auto node=q.front();
            q.pop();
            int to=edges[node];
            if(to==-1){
                continue;
            }
            indeg[to]--;
            if(indeg[to]==0){
                q.push(to);
                vis[to]=1;
            }
        }
       
        int res=-1;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                int x=i;
                int ct=0;
                while(vis[x]==0){
                    ct++;
                    vis[x]=1;
                    x=edges[x];
                }
                res=max(res,ct);
            }
        }
        
        return res;
    }
};