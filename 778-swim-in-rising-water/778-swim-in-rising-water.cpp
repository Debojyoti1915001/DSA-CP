class Solution {
public:
    //we know the ans lies between 0 to n*n
    //think of a possible algorithm 
    //think of binary search
    vector<int>dirs{0,-1,0,1,0};
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int lo=0,hi=n*n-1,res=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(valid(grid,mid)){
                res=mid;
                hi=mid-1;
            }else lo=mid+1;
        }
        return res;
    }
    bool valid(vector<vector<int>>& grid,int mx){
        int n=grid.size();
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        //if the current value is more than mx 
        if(grid[0][0]>mx)return false;
        if(n==1&&grid[0][0]<=mx)return true;
        return dfs(grid,vis,0,0,mx,n);
    }
    bool dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,int r,int c,int mx,int n){
        vis[r][c]=true;
        for(int i=0;i<4;i++){
            int nr=r+dirs[i];
            int nc=c+dirs[i+1];
            //if the new index is a valid index and we have not visited the following index
            if(nr>=0&&nc>=0&&nr<n&&nc<n&&grid[nr][nc]<=mx&&vis[nr][nc]==false){
                if(nr==n-1&&nc==n-1)return true;
                if(dfs(grid,vis,nr,nc,mx,n))return true;
            }
        }
        return false;
    }
};