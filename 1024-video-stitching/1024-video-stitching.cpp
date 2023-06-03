class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int>dp(time+2,1e9);
        dp[0]=0;
        for(int i=0;i<=time;i++){
            for(auto clip:clips){
                if(clip[0]<=i&&i<=clip[1]){
                    dp[i]=min(dp[i],dp[clip[0]]+1);
                }
            }
            if(dp[i]==1e9)return -1;
        }
        return dp[time];
    }
};