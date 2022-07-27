class Solution {
public:
    int n;
    int dp[55][55][55];
    vector<vector<int>>dirs{{1,0,1},{0,1,1},{1,0,0},{0,1,0}};
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
        int further=INT_MIN;
        for(auto i:dirs){
            if(dp[r1+i[0]][c1+i[1]][r2+i[2]]==-1)
            dp[r1+i[0]][c1+i[1]][r2+i[2]]=solve(g,r1+i[0],c1+i[1],r2+i[2]);
            further=max(further,dp[r1+i[0]][c1+i[1]][r2+i[2]]);
        }
        c=c+further;
        return dp[r1][c1][r2]=c;
    }
    int cherryPickup(vector<vector<int>>& g) {
        n=g.size();
        memset(dp,-1,sizeof(dp));
        return max(0,solve(g,0,0,0));
    }
};