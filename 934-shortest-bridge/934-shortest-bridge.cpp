class Solution {
public:
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
        int f=1;
        for(int i=0;i<n&&f;i++){
            for(int j=0;j<m&&f;j++){
                if(g[i][j]){
                    dfs(g,i,j);
                    f=0;
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