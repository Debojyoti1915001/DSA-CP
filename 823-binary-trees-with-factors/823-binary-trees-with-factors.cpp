class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,long>dp;
        sort(arr.begin(),arr.end());
        int ans=0,mod=1e9+7;
        for(int i=0;i<n;i++){
            dp[arr[i]]=1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0)
                dp[arr[i]]=(dp[arr[i]]+dp[arr[j]]*(dp[arr[i]/arr[j]]))%mod;
            }
            ans=(ans+dp[arr[i]])%mod;
        }
        return ans;                                              
    }
};
