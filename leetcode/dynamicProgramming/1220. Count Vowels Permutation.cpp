//https://leetcode.com/problems/count-vowels-permutation/

class Solution {
public:
    int countVowelPermutation(int n) {
       vector<vector<long long int>>dp(n+1,vector<long long int>(5));
        int mod=pow(10,9)+7;
        for(int i=0;i<=n;i++){
            if(i==0){
                continue;
            }else if(i==1){
                dp[i][0]=1;
                dp[i][1]=1;
                dp[i][2]=1;
                dp[i][3]=1;
                dp[i][4]=1;
            }else{
                dp[i][0]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][4])%mod;
                dp[i][1]=(dp[i-1][2]+dp[i-1][0])%mod;
                dp[i][2]=(dp[i-1][1]+dp[i-1][3])%mod;
                dp[i][3]=(dp[i-1][2])%mod;
                dp[i][4]=(dp[i-1][2]+dp[i-1][3])%mod;
            }
        }
        long long int ans=0;
        for(int i=0;i<5;i++)ans=(ans+dp[n][i])%mod;
        return ans%mod;
    }
};