class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1);
        for(int i=0;i<=n;i++){
            if(i==0){
                dp[i]=cost[i];
            }else if(i==1){
                dp[i]=cost[i];
            }else if(i==n){
                dp[i]=min(dp[i-1],dp[i-2]);
            }else{
                //cur cost+min to reach the last or last second step
                dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
            }
        }
        return dp[n];
    }
};