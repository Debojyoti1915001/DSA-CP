class Solution {
public:
    int n,m;
    int dp[85][85][85];
    int solve(vector<vector<int>>& g,int c1,int c2,int r){
        if(r==n)return 0;
        if(dp[c1][c2][r]!=-1)return dp[c1][c2][r];
        int ans=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int C1=c1+i;
                int C2=c2+j;
                if(C1>=0&&C1<m&&C2>=0&&C2<m){
                    ans=max(ans,solve(g,C1,C2,r+1));
                }
            }
        }
        if(c1==c2)ans+=g[r][c1];
        else ans+=g[r][c1]+g[r][c2];
        return dp[c1][c2][r]=ans;
    }
    int cherryPickup(vector<vector<int>>& g) {
        n=g.size();
        m=g[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(g,0,m-1,0);
    }
};