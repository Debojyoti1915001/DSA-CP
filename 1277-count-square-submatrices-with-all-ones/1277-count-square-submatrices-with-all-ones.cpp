class Solution {
public:
    int countSquares(vector<vector<int>>& dp) {
        int res=0;
        int n=dp.size();
        int m=dp[0].size();
        for(int i=0;i<n;i++){
            res+=dp[i][0];
        }
        for(int i=1;i<m;i++){
            res+=dp[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(dp[i][j]){
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                    res+=dp[i][j];
                }
            }
        }
        return res;
    }
};