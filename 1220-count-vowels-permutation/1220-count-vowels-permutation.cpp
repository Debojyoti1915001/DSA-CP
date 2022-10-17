class Solution {
public:
    int countVowelPermutation(int n) {
        vector<int>dp(5,1);
        int mod=1e9+7;
        for(int i=1;i<n;i++){
            vector<int>dp1(5);
            dp1[0]=dp[1];
            dp1[1]=(dp[0]+dp[2])%mod;
            dp1[2]=((dp[0]+dp[1])%mod+(dp[3]+dp[4])%mod)%mod;
            dp1[3]=(dp[2]+dp[4])%mod;
            dp1[4]=dp[0];
            swap(dp,dp1);
        }
        int ans=0;
        for(auto i:dp)ans=(ans+i)%mod;
        return ans;
    }
};