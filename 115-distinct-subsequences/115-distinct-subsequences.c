

int numDistinct(char * s, char * t){
    int n=strlen(s);
    int m=strlen(t);
    unsigned int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    int i,j;
    for(i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}