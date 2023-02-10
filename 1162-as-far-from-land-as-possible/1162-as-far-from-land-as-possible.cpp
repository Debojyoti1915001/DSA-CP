class Solution {
public:
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int maxDistance(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1){
                q.push({i,j});
                g[i][j]=-1;
                }
            }
        }
        if(q.size()==n*m||q.size()==0)return -1;
        int cur=0;
        while(q.size()){
            int sz=q.size();
            while(sz--){
                auto [x,y]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nx=x+dir[k][0];
                    int ny=y+dir[k][1];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m){
                        if(g[nx][ny]!=-1)
                        {
                            g[nx][ny]=-1;
                            q.push({nx,ny});
                        }
                    }
                }
            }
            cur++;
        }
        return cur-1;
    }
};