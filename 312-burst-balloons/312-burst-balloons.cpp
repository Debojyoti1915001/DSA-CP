class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,vector<int>& nums){
        // if the size of the current vector is 2 return 0
        if(i+1==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        for(int k=i+1;k<j;k++){
            //apply mcm i.e. select two index and iterate over the third to find max value that can be obtained
            if(dp[i][k]==-1)dp[i][k]=solve(i,k,nums);
            if(dp[k+1][j]==-1)dp[k][j]=solve(k,j,nums);
            ans=max(ans,dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j]);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        //since it is multiplication we need to push back and push front 1 in the vector
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        dp=vector<vector<int>>(n,vector<int>(n,-1));
        return solve(0,n-1,nums);
    }
};