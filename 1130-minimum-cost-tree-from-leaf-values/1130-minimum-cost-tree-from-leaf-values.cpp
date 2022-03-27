class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>& arr,int i,int j){
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==j)return dp[i][j]=0;
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            if(dp[i][k]==-1)dp[i][k]=solve(arr,i,k);
            if(dp[k+1][j]==-1)dp[k+1][j]=solve(arr,k+1,j);
            int f=*max_element(arr.begin()+i,arr.begin()+k+1);
            int s=*max_element(arr.begin()+k+1,arr.begin()+j+1);
            ans=min(ans,dp[i][k]+dp[k+1][j]+(f)*(s));
        }
        return ans;
        
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        dp=vector<vector<int>>(n+1,vector<int>(n+1,-1));
        return solve(arr,0,n-1);
    }
};