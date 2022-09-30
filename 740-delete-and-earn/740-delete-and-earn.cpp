class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int>dp(10005);
        for(auto &n:nums){
            dp[n]+=n;
        }
        int take=0,skip=0;
        for(int i=0;i<10005;i++){
            int takei=skip+dp[i];//skip the prev element
            int skipi=max(skip,take);//max of prev take and skip which doesn't include 
            take=takei;
            skip=skipi;
        }
        return max(take,skip);
    }
};