

int change(int m, int* coins, int n){
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++)dp[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j>=coins[i-1]){
                dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}