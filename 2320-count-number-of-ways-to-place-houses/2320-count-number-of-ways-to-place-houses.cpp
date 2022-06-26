class Solution {
public:
    int countHousePlacements(int n) {
        vector<long long>dp(n+10);
        dp[1]=2;
        dp[2]=3;
        int mod=1e9+7;
        for(int i=3;i<=n;i++){
            //for road if it is in one way
            dp[i]=(dp[i-1]+dp[i-2])%mod;
        }
        return dp[n] * dp[n]%mod;
    }
};