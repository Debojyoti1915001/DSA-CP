class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& g) {
        int ans=0;
        vector<vector<int>>dpx(g.size(),vector<int>(g[0].size()));
        vector<vector<int>>dpy(g.size(),vector<int>(g[0].size()));
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]=='X'){
                    if(i==0&&j==0){
                        dpx[i][j]=1;
                    }else if(i==0){
                        dpx[i][j]=dpx[i][j-1]+1;
                    }else if(j==0){
                        dpx[i][j]=dpx[i-1][j]+1;
                    }else{
                        dpx[i][j]=dpx[i-1][j]+dpx[i][j-1]+1-dpx[i-1][j-1];
                    }
                }
                if(g[i][j]=='Y'){
                    if(i==0&&j==0){
                        dpy[i][j]=1;
                    }else if(i==0){
                        dpy[i][j]=dpy[i][j-1]+1;
                    }else if(j==0){
                        dpy[i][j]=dpy[i-1][j]+1;
                    }else{
                        dpy[i][j]=dpy[i-1][j]+dpy[i][j-1]+1-dpy[i-1][j-1];
                    }
                }
                    if(i==0&&j==0)continue;
                    else if(i==0){
                        if(g[i][j]=='Y'||g[i][j]=='.')dpx[i][j]=dpx[i][j-1];
                        if(g[i][j]=='X'||g[i][j]=='.')dpy[i][j]=dpy[i][j-1];
                    }else if(j==0){
                        if(g[i][j]=='Y'||g[i][j]=='.')dpx[i][j]=dpx[i-1][j];
                        if(g[i][j]=='X'||g[i][j]=='.')dpy[i][j]=dpy[i-1][j];
                    }else{
                        if(g[i][j]=='Y'||g[i][j]=='.')dpx[i][j]=dpx[i-1][j]+dpx[i][j-1]-dpx[i-1][j-1];
                        if(g[i][j]=='X'||g[i][j]=='.')dpy[i][j]=dpy[i-1][j]+dpy[i][j-1]-dpy[i-1][j-1];
                    }
                
                if(dpy[i][j]!=0&&dpx[i][j]==dpy[i][j])ans++;
            }
        }
        return ans;
    }
};