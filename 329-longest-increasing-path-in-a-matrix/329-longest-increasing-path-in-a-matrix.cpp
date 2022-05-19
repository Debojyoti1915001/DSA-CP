class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
    int solve(vector<vector<int>>& mat,int i,int j){
        if(i<0||j<0||i>=n||j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int cur=0;
        for(int k=0;k<4;k++){
            int ni=i+dir[k].first;
            int nj=j+dir[k].second;
            if(ni>=0&&nj>=0&&ni<n&&nj<m&&mat[ni][nj]>mat[i][j]){
                cur=max(cur,solve(mat,ni,nj));
            }
        }
        return dp[i][j]=cur+1;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        int ans=1;
        dp=vector<vector<int>>(n, vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cur=solve(mat,i,j);
                ans=max(ans,cur);
            }
        }
        return ans;
    }
};