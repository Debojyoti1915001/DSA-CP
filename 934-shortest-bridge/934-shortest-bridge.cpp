class Solution {
public:
    // https://leetcode.com/problems/shortest-bridge/discuss/189293/C%2B%2B-BFS-Island-Expansion-%2B-UF-Bonus
    vector<int>dirs{0,1,0,-1,0};
    queue<pair<int,int>>q;
    void dfs(vector<vector<int>>& g,int i,int j){
        if(i>=g.size()||j>=g[0].size()||i<0||j<0||g[i][j]!=1)return;
        g[i][j]=2;
        q.push({i,j});
        for(int k=0;k<4;k++){
            dfs(g,i+dirs[k],j+dirs[k+1]);
        }
    }
    int shortestBridge(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        for(int i=0;i<n&&q.size()==0;i++){
            for(int j=0;j<m&&q.size()==0;j++){
                if(g[i][j]){
                    dfs(g,i,j);
                }
            }
        }
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int ni=i+dirs[k];
                    int nj=j+dirs[k+1];
                    if(ni<g.size()&&nj<g[0].size()&&ni>=0&&nj>=0){
                        if(g[ni][nj]==0){
                            g[ni][nj]=g[i][j]+1;
                            q.push({ni,nj});
                        }else if(g[ni][nj]==1){
                            return g[i][j]-2;
                        }
                    }
                }
            }
        }
        return 0;
    }
};