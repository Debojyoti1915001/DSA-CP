#define ll long long
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<ll>dp(n);
        dp[0]=1;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            for(int j=i+delay;j<min(i+forget,n);j++){
                //imp
                dp[j]=(dp[j]%mod+dp[i]%mod)%mod;
            }
        }
        ll ans=0;
        for(int i=n-forget;i<n;i++){
            ans=(ans%mod+dp[i]%mod)%mod;
        }
        return ans;
    }
};