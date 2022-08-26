class Solution {
public:
    int matrixScore(vector<vector<int>>& g) {
        for(auto &i:g){
            if(i[0]==0){
                for(auto &j:i){
                    j=1-j;
                }
            }
        }
        for(int j=0;j<g[0].size();j++){
            int z=0,o=0;
            for(int i=0;i<g.size();i++){
                if(g[i][j]==0)z++;
                else o++;
            }
            if(z>o){
             for(int i=0;i<g.size();i++){
                g[i][j]=1-g[i][j];
            }   
            }
        }
        int ans=0;
        for(auto &i:g){
            int cur=0;
            for(auto &j:i){
                cur=cur*2+j;
            }
            ans+=cur;
        }
        return ans;
    }
};