class Solution {
public:
    int dir[8][2]={{0,1},{1,0},{1,1},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        if(g[0][0]==1)return -1;
        queue<pair<int,int>>q;
        int ans=0;
        q.push({0,0});
        while(q.size()){
            ans++;
            int sz=q.size();
            while(sz--){
                auto[a,b]=q.front();
                q.pop();
                if(a==n-1&&b==m-1){
                    return ans;
                }
                for(int i=0;i<8;i++){
                    int na=a+dir[i][0];
                    int nb=b+dir[i][1];
                    if(na>=0&&nb>=0&&na<n&&nb<m&&g[na][nb]==0){
                        q.push({na,nb});
                        g[na][nb]=1;
                    }
                }
            }
        }
        return -1;
    }
};