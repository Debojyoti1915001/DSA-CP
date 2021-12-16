// https://leetcode.com/problems/longest-arithmetic-subsequence/

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size(),res=2;
        vector<vector<int>>dp(n,vector<int>(2000,0));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                //since i is fixed and we change vary j
                int d=nums[j]-nums[i]+1000;
                dp[j][d]=max(dp[i][d]+1,2);
                res=max(res,dp[j][d]);
            }
        }
        return res;
    }
};