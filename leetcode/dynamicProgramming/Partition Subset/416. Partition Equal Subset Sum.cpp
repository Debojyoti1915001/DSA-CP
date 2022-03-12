class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);//to find the total sum
        int n=nums.size();
        if(sum%2)return false;
        vector<vector<int>>dp(n+1,vector<int>(sum/2+1));
        //when sum=0 it is always possible
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum/2;j++){
                // if j is more than nums[i] we have to options 
                //wheather to include or not to include the current element
                if(j>=nums[i-1]){
                    dp[i][j]=dp[i-1][j-nums[i-1]]||dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum/2];
    }
};