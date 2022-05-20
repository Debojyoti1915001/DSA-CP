class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<long long int>>dp(n,vector<long long int>(m));
        for(int i=n-1;i>=0;i--){
            if(g[i][m-1]==1)break;
            dp[i][m-1]=1;
        }
        for(int j=m-1;j>=0;j--){
            if(g[n-1][j]==1)break;
            dp[n-1][j]=1;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(g[i][j]==1)continue;
                dp[i][j]=dp[i][j+1]+dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};