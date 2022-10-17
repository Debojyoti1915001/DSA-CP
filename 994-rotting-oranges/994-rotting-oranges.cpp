class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        queue<pair<int,int>>q;
        int no=0,ans=0;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==2)q.push({i,j});
                if(g[i][j]==1)no++;
            }
        }
        vector<int>dirs={0,1,0,-1,0};
        while(q.size()){
            int sz=q.size();
            // cout<<sz<<" ";
            while(sz--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int ni=i+dirs[k];
                    int nj=j+dirs[k+1];
                    if(ni>=0&&nj>=0&&ni<g.size()&&nj<g[0].size()&&g[ni][nj]==1){
                        g[ni][nj]=2;
                        no--;
                        q.push({ni,nj});
                    }
                }
            }
            ans++;
        }
        return no==0?max(0,ans-1):-1;
    }
};