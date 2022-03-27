class Solution {
public:
    int coinChange(vector<int>& v, int m) {
        int n=v.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        //for money if no of coins is zero
        for(int j=1;j<=m;j++){
            dp[0][j]=INT_MAX-1;
        }
        for(int j=1;j<=m;j++){
            if(j%v[0]==0){
                dp[1][j]=j/v[0];
            }else{
                dp[1][j]=INT_MAX-1;
            }
        }
        // remember to take INT_MAX-1 cause it will show overflow when added with 1
        for(int i=2;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(j>=v[i-1]){
                    //dp[i][j-v[i-1]]+1 means we are adding one more coin of type v[i-1] 
                    // here we are not taking i-1 cause we can add more coins of type v[i-1]
                    //dp[i-1][j]  means we are not adding that coin
                    dp[i][j]=min(dp[i][j-v[i-1]]+1,dp[i-1][j]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m]==INT_MAX-1?-1:dp[n][m];
    }
};