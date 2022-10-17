class Solution {
public:
    int n,m;
    vector<int>dx={0,1,0,-1};
    vector<int>dy={1,0,-1,0};
    void dfs(vector<vector<int>>& ht,vector<vector<int>>&vis,int i,int j){
        if(i>=n||j>=m||i<0||j<0)return;
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=n||nj>=m||ni<0||nj<0)continue;
            if(vis[ni][nj]==0&&ht[ni][nj]>=ht[i][j]){
                dfs(ht,vis,ni,nj);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& ht) {
        vector<vector<int>>res;
        n=ht.size();
        m=ht[0].size();
        if(n==0||m==0)return res;
        vector<vector<int>>pacific(n,vector<int>(m));
        vector<vector<int>>atlantic(n,vector<int>(m));
        for(int i=0;i<n;i++){
            dfs(ht,pacific,i,0);
            dfs(ht,atlantic,i,m-1);
        }
        for(int j=0;j<m;j++){
            dfs(ht,pacific,0,j);
            dfs(ht,atlantic,n-1,j);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atlantic[i][j]&&pacific[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};