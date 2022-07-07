class Solution {
public:
    bool solve(string a, string b, string c,int i,int j,int k){
        if(i==a.length()&&j==b.length())return true;
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i]==c[k]||b[j]==c[k]){
            bool can1=false,can2=false;
            if(a[i]==c[k])
            can1=solve(a,b,c,i+1,j,k+1);
            if(b[j]==c[k])
            can2=solve(a,b,c,i,j+1,k+1);
            return dp[i][j]=can1||can2;
        }else
            return dp[i][j]=0;
    }
    vector<vector<int>>dp;
    bool isInterleave(string s1, string s2, string s3) {
        dp=vector<vector<int>>(105,vector<int>(105,-1));
        if(s1.length()+s2.length()!=s3.length())return false;
        return solve(s1,s2,s3,0,0,0);
    }
};