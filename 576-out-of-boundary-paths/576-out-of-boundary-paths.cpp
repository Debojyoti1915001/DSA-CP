class Solution {
public:
    int dp[105][105][105];
    int mod=1e9+7;
    vector<int>dirs{0,1,0,-1,0};
    int dfs(int m, int n, int maxMove, int i, int j){
        if(i>=m||j>=n||i<0||j<0)return 1;
        if(maxMove==0)return 0;
        if(dp[i][j][maxMove]!=-1)return dp[i][j][maxMove];
        int ans=0;
        for(int k=0;k<4;k++){
            int ni=i+dirs[k];
            int nj=j+dirs[k+1];
            ans=(ans+dfs(m,n,maxMove-1,ni,nj))%mod;
        }
        return dp[i][j][maxMove]=ans;
    }
    int findPaths(int m, int n, int maxMove, int i, int j) {
        memset(dp,-1,sizeof(dp));
        return dfs(m,n,maxMove,i,j);    
    }
};