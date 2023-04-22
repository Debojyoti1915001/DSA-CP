class Solution {
public:
    int palindrome(string a,string b){
        int n=a.length();
        int dp[n+1][n+1];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
                else if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
    int minInsertions(string s) {
        string str=s;
        reverse(s.begin(),s.end());
        return s.length()-palindrome(s,str);
    }
};