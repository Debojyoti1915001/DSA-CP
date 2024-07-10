class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(k));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int rem=(nums[i]+nums[j])%k;
                dp[j][rem]=max(dp[i][rem]+1,dp[j][rem]);
                ans=max(ans,dp[j][rem]);
            }
        }
        return ans+1;
    }
};