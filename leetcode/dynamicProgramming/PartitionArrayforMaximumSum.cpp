// https://leetcode.com/problems/partition-array-for-maximum-sum/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n);
        int mx=arr[0];
        for(int i=0;i<k;i++){
            mx=max(mx,arr[i]);
            dp[i]=mx*(i+1);
        }
        for(int i=k;i<n;i++){
            mx=arr[i];
            for(int j = 0;j <k;j++){
                mx=max(mx,arr[i-j]);
                dp[i]=max(dp[i],dp[i-j-1]+(mx*(j+1)));
            }
        }
        return dp[n-1];
    }
};