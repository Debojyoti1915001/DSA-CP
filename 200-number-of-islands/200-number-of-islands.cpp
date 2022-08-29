class Solution {
public:
    int n,m;
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i>=n||j>=m||i<0||j<0||grid[i][j]=='0')return;
        grid[i][j]='0';
        for(int k=0;k<4;k++)dfs(grid,i+dir[k][0],j+dir[k][1]);
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1')c++,dfs(grid,i,j);
            }
        }
        return c;
    }
};