class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2000,0));
        int ans=2;
        if(n==1)return 1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                //if we go from ith to the jth element add 1
                int d=nums[j]-nums[i]+500;
                dp[j][d]=max(2,dp[i][d]+1);
                // cout<<d<<" "<<dp[d]<<endl;
                ans=max(dp[j][d],ans);
            }
        }
        return ans;
    }
};