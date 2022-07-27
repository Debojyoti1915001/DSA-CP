class Solution {
public:
    int dp[50][50][50];
    int solution(vector<vector<int>>& grid,int r1,int c1,int r2){
        int n=grid.size();
        int c2=r1+c1-r2;
        if(r1>=n||c1>=n||r2>=n||c2>=n||grid[r1][c1]==-1||grid[r2][c2]==-1)return INT_MIN;
        if(dp[r1][c1][r2]!=-1)return dp[r1][c1][r2];
        int cherries=0;
        if(r1==n-1&&c1==n-1)return grid[r1][c1];
        if(r1==r2&&c1==c2){
            cherries+=grid[r1][c1];
        }else{
            cherries+=grid[r1][c1]+grid[r2][c2];
        }
        int f1=solution(grid,r1+1,c1,r2+1);
        int f2=solution(grid,r1,c1+1,r2);
        int f3=solution(grid,r1+1,c1,r2);
        int f4=solution(grid,r1,c1+1,r2+1);
        cherries+=max({f1,f2,f3,f4});
        return dp[r1][c1][r2]=cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        memset(dp,-1,sizeof(dp));
        return max(0,solution(grid,0,0,0));
    }
};