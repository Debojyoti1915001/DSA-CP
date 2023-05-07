class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& ob) {
        int n=ob.size();
        vector<int>dp(n+1,INT_MAX),ans(n);
        dp[0]=INT_MIN;
        for(int i=0;i<n;i++){
            int idx=upper_bound(dp.begin(),dp.end(),ob[i])-dp.begin();
            if(dp[idx]>ob[i])dp[idx]=ob[i];
            ans[i]=idx;
        }
        return ans;
    }
};