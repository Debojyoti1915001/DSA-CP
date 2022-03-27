class Solution {
public:
    vector<vector<int>>dp;
    int mcm(int i,int j,vector<int>& values){
        if(i==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            if(dp[i][k]==-1)dp[i][k]=mcm(i,k,values);
            if(dp[k+1][j]==-1)dp[k+1][j]=mcm(k+1,j,values);
            ans=min(ans,dp[i][k]+dp[k+1][j]+values[i-1]*values[k]*values[j]);
        }
        return ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        dp=vector<vector<int>>(n+1,vector<int>(n+1,-1));
        //we fix two element
        return mcm(1,n-1,values);
    }
};