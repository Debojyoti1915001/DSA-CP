class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& eps) {
        int n=eps.size();
        sort(eps.begin(),eps.end(),comp);
        vector<int>dp(n+1,INT_MAX);
        dp[0]=INT_MIN;
        int ans=1;
        for(int i=0;i<eps.size();i++){
            int idx=lower_bound(dp.begin(),dp.end(),eps[i][1])-dp.begin();
            ans=max(ans,idx);
            dp[idx]=eps[i][1];
        }
        return ans;
    }
};