class Solution {
public:
    vector<vector<int>>dp;
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length() != s3.length()) return false;
        dp=vector<vector<int>>(s1.size()+1, (vector<int>(s2.size()+1, -1)));
        return helper(0, 0, 0, s1, s2, s3);
    }
    
    bool helper(int i, int j, int k, string s1, string s2, string s3){
        
        if(dp[i][j]!=-1)return dp[i][j];
        if(i == s1.length() && j == s2.length()) return true;
        
        if(s1[i] == s3[k] && s2[j] == s3[k]){
            return dp[i][j]=(helper(i+1, j, k+1, s1, s2, s3) || helper(i, j+1, k+1, s1, s2, s3));
        }
        
        else if(s1[i] == s3[k]) return dp[i][j]=helper(i+1, j, k+1, s1, s2, s3);
        else if(s2[j] == s3[k]) return dp[i][j]=helper(i, j+1, k+1, s1, s2, s3);
        
        return dp[i][j]=false;
    }
};