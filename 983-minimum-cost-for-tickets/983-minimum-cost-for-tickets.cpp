class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n=days.size();
        vector<int>dp(days[n-1]+1);
        int j=0;
        for(int i=1;i<=days[n-1];i++){
            // cout<<i<<" ";
            if(days[j]==i){
                j++;//remember to keep a check on days
                dp[i]=min({dp[i-1]+cost[0],dp[max(i-7,0)]+cost[1],dp[max(i-30,0)]+cost[2]});
            }else{
                dp[i]=dp[i-1];
            }
        }
        return dp[days[n-1]];
    }
};