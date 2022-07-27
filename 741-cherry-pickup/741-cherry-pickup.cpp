class Solution {
public:
    int n;
    int dp[55][55][55];
    int solve(vector<vector<int>>& g,int r1,int c1,int r2){
        int c2=r1+c1-r2;
        if(r1>=n||r2>=n||c1>=n||c2>=n||g[r1][c1]==-1||g[r2][c2]==-1)return INT_MIN;
        if(dp[r1][c1][r2]!=-1)return dp[r1][c1][r2];
        if(r1==n-1&&c1==n-1)return g[r1][c1];
        int c=0;
        if(r1==r2&&c1==c2){
            c=g[r1][c1];
        }else{
            c=g[r2][c2]+g[r1][c1];
        }
        if(dp[r1+1][c1][r2+1]==-1)
        dp[r1+1][c1][r2+1]=solve(g,r1+1,c1,r2+1);
        if(dp[r1][c1+1][r2+1]==-1)
        dp[r1][c1+1][r2+1]=solve(g,r1,c1+1,r2+1);
        if(dp[r1+1][c1][r2]==-1)
        dp[r1+1][c1][r2]=solve(g,r1+1,c1,r2);
        if(dp[r1][c1+1][r2]==-1)
        dp[r1][c1+1][r2]=solve(g,r1,c1+1,r2);
        int mx=max({dp[r1+1][c1][r2+1],dp[r1][c1+1][r2+1],dp[r1+1][c1][r2],dp[r1][c1+1][r2]});
        c+=mx;
        return dp[r1][c1][r2]=c;
    }
    int cherryPickup(vector<vector<int>>& g) {
        n=g.size();
        memset(dp,-1,sizeof(dp));
        return max(0,solve(g,0,0,0));
    }
};