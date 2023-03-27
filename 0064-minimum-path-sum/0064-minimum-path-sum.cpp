class Solution {
public:
    void solve(vector<vector<int>>& grid,int cur,int m,int n,int i,int j,int &ans){
        if(i==m-1&&j==n-1){
            ans=min(ans,cur);
            //cout<<ans<<endl;
            return;
        }
        if(cur>ans){
            return;
        }
        if(i<m-1){
            solve(grid,cur+grid[i+1][j],m,n,i+1,j,ans);
        }
        if(j<n-1){
            solve(grid,cur+grid[i][j+1],m,n,i,j+1,ans);
        }
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n=grid[0].size();
        // int ans=1000005;
        // solve(grid,grid[0][0],m,n,0,0,ans);
        // return ans;
        for(int i=1;i<m;i++){
            grid[i][0]=grid[i][0]+grid[i-1][0];
        }
        for(int j=1;j<n;j++){
            grid[0][j]=grid[0][j-1]+grid[0][j];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                grid[i][j]=grid[i][j]+min(grid[i][j-1],grid[i-1][j]);
            }
        }
        return grid[m-1][n-1];
    }
};