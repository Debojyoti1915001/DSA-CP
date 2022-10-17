class Solution {
public:
    int mod=1e9+7;
    int dx[8]={2,2,-2,-2,1,1,-1,-1};
    int dy[8]={1,-1,1,-1,2,-2,2,-2};
    vector<vector<int>>g={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
    int solve(int id,int i,int j,vector<vector<int>>&dp,int n,int last){
        if(id==n-1)return 1;
        if(dp[id][last]!=-1)return dp[id][last];
        int ans=0;
        for(int k=0;k<8;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0&&nj>=0&&ni<4&&nj<3&&g[ni][nj]!=-1)
            ans=(ans+solve(id+1,ni,nj,dp,n,g[ni][nj]))%mod;
        }
        return dp[id][last]=ans;
    }
    int knightDialer(int n) {
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(10,-1));
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(g[i][j]!=-1){
                    ans=(ans+solve(0,i,j,dp,n,g[i][j]))%mod;
                }
            }
        }
        return ans;
    }
};