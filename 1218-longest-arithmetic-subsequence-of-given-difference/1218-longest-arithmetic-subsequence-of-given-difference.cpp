class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        vector<int>dp(40005);//an alternative of map to improve performance
        int ans=1;
        for(auto x:arr){
            //for neg value add 20000
            dp[x+20000]=dp[x+20000-diff]+1;
            ans=max(ans,dp[x+20000]);
        }
        return ans;
    }
};