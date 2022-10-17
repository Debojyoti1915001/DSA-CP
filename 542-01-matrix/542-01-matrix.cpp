class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==0)q.push({i,j});
                else g[i][j]=-1;
            }
        }
        int cur=0;
        vector<int>dirs={0,1,0,-1,0};
        while(q.size()){
            int sz=q.size();
            while(sz--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int ni=i+dirs[k];
                    int nj=j+dirs[k+1];
                    if(ni>=0&&nj>=0&&ni<n&&nj<m&&g[ni][nj]==-1){
                        q.push({ni,nj});
                        g[ni][nj]=cur+1;
                    }
                }
            }
            cur++;
        }
        return g;
    }
};