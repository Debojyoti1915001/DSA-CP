class Solution {
public:
    int n,m;
    vector<pair<int,int>>dir{{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(vector<vector<int>>& g,int i,int j,int &c){
        if(i>=n||j>=m||i<0||j<0||g[i][j]==0)return;
        g[i][j]=0;
        c++;
        for(int k=0;k<4;k++){
            int ni=i+dir[k].first;
            int nj=j+dir[k].second;
            dfs(g,ni,nj,c);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& g) {
        n=g.size();
        m=g[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int c=0;
                if(g[i][j])
                dfs(g,i,j,c);
                ans=max(c,ans);
            }
        }
        return ans;
    }
};