class Solution {
public:
//      dp[n][k] = dp[n-1][k]+dp[n-1][k-1]+dp[n-1][k-2]+...+dp[n-1][k+1-n+1]+dp[n-1][k-n+1]
//      dp[n][k+1] = dp[n-1][k+1]+dp[n-1][k]+dp[n-1][k-1]+dp[n-1][k-2]+...+dp[n-1][k+1-n+1]
    int kInversePairs(int n, int k) {
        if(k>(n*(n-1))/2||k<0)return 0;
        if(k==(n*(n-1))/2||k==0)return 1;
        int mod=1e9+7;
        vector<vector<long long int>>dp(n+1,vector<long long int>(k+1));
        dp[2][0]=1;
        dp[2][1]=1;
        for(int i=3;i<=n;i++){
            dp[i][0]=1;
            for(int j=1;j<=min(k,(i*(i+1))/2);j++){
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
                if(j>=i)dp[i][j]-=dp[i-1][j-i];
                dp[i][j]=(dp[i][j]+mod)%mod;
            }
        }
        return dp[n][k]%mod;
    }
};