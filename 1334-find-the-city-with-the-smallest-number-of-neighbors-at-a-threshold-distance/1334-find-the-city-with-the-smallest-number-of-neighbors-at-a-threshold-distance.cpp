class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>>dis(n,vector<int>(n,10001));
        for(auto &e:edges){
            dis[e[0]][e[1]]=e[2];
            dis[e[1]][e[0]]=e[2];
        }
        for(int i=0;i<n;i++){
            dis[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
                }
            }
        }
        int mn=n,res=0;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(dis[i][j]<=d){
                    c++;
                }
            }
            if(c<=mn){
                res=i;
                mn=c;
            }
        }
        return res;
    }
};