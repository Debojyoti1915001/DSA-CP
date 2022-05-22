class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int c=0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;j++,i++){
                if(g==0){
                    dp[i][j]=true;
                }else if(g==1){
                    if(s[i]==s[j]){
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=false;
                    }
                }else{
                    if(s[i]==s[j]&&dp[i+1][j-1]){
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=false;
                    }
                }
                // cout<<dp[i][j]<<" ";
                if(dp[i][j])c++;
            }
        }
        return c;
    }
};