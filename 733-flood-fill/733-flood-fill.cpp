class Solution {
public:
    int n,m;
    vector<int>dirs={0,-1,0,1,0};
    void dfs(vector<vector<int>>& g, int i, int j, int color,int old){
        if(i>=n||j>=m||i<0||j<0||g[i][j]==color)return;
        if(g[i][j]==old){
            g[i][j]=color;
            for(int k=0;k<4;k++){
                dfs(g,i+dirs[k],j+dirs[k+1],color,old);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& g, int sr, int sc, int color) {
        n=g.size();
        m=g[0].size();
        dfs(g,sr,sc,color,g[sr][sc]);
        return g;
    }
};