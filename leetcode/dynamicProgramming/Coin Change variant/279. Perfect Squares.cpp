class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                //reduce the square of j and add 1 cause you are adding a new element and find minimum among them
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};