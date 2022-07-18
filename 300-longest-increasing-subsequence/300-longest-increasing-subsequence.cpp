class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,INT_MAX);
        dp[0]=INT_MIN;
        int res=0;
        for(int i=0;i<n;i++){
            int idx=lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
            res=max(res,idx);
            dp[idx]=nums[i];
        }
        return res;
    }
};