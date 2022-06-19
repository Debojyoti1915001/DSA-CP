class Solution {
public:
    // For a piece of w * h,

// we can make a vertical cut to split it into a * h and (w - a) * h
// So we can update dp[w][h] = max(dp[w][h], dp[a][h] + dp[w - a][h]).

// we can make a horizontal cut to split it into w * a and w * (h - a)
// So we can update dp[w][h] = max(dp[w][h], dp[w][a] + dp[w][h - a]).
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>>dp(m+1,vector<long long>(n+1));
        //setting up the prices 
        for(auto p:prices){
            dp[p[0]][p[1]]=p[2];
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                for(int k=0;k<=i/2;k++){
                    dp[i][j]=max(dp[i][j],dp[i-k][j]+dp[k][j]);
                }
                for(int k=0;k<=j/2;k++){
                    dp[i][j]=max(dp[i][j],dp[i][j-k]+dp[i][k]);
                }
            }
        }
        return dp[m][n];
    }
};