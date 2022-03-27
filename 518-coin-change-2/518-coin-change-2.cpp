class Solution {
public:
    int change(int m, vector<int>& v) {
        int n=v.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(j>=v[i-1]){
                    dp[i][j]=dp[i-1][j]+dp[i][j-v[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};