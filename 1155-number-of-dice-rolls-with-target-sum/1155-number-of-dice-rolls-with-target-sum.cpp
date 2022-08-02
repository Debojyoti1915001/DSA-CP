class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<int>dp(target+1);
        dp[0]=1;
        int mod=1e9+7;
        for(int i=1;i<=n;i++){
            vector<int>dp1(target+1);
            for(int j=1;j<=k;j++){
                for(int k=j;k<=target;k++){
                    dp1[k]=(dp1[k]+dp[k-j])%mod;
                }
            }
            swap(dp,dp1);
        }
        return dp[target];
    }
};