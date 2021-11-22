// https://leetcode.com/problems/ones-and-zeroes/

class Solution {
public:
//     RECURSIVE
    int solve(vector<string>& strs, int m, int n,int i){
        if(i==strs.size() || m<0 || n<0) return 0;
        if(m==0 && n==0) return 0;
        int zeros = count(strs[i].begin(),strs[i].end(),'0');
        int ones = strs[i].length()-zeros;
        if(zeros<=m && ones<=n) return max(solve(strs,m,n,i+1) , solve(strs,m-zeros,n-ones,i+1)+1);
        else return solve(strs,m,n,i+1);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        return solve(strs,m,n,0);      
    }
};
class Solution {
public:
//     MEMO
    int solve(vector<string>& strs, int m, int n,int i,vector<vector< vector<int>>>& memo){
        if(i==strs.size() || m<0 || n<0) return 0;
        if(m==0 && n==0) return 0;
        if(memo[i][m][n]!=-1) return memo[i][m][n];
        int zeros = count(strs[i].begin(),strs[i].end(),'0');
        int ones = strs[i].length()-zeros;
        if(zeros<=m && ones<=n) return memo[i][m][n] = max(solve(strs,m,n,i+1,memo) , solve(strs,m-zeros,n-ones,i+1,memo)+1);
        else return memo[i][m][n] = solve(strs,m,n,i+1,memo);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
vector<vector< vector<int> > > memo(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(strs,m,n,0,memo);      
    }
};
class Solution {
public:
//     DP
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for (auto &s: strs) {
            int ones = count(s.begin(), s.end(), '1');
            int zeros= s.size()-ones;
            for (int i=m; i>=zeros; i--) 
                for (int j=n; j>=ones; j--)
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1); //reject or accept whichever is max
        }
        return dp[m][n];
    }
};
// memo[i][j] = the max number of strings that can be formed with i 0's and j 1's
    // from the first few strings up to the current string s
    // Catch: have to go from bottom right to top left
    // Why? If a cell in the memo is updated(because s is selected),
    // we should be adding 1 to memo[i][j] from the previous iteration (when we were not considering s)
    // If we go from top left to bottom right, we would be using results from this iteration => overcounting