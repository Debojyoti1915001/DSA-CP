class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int ans=1;
        for(int i=0;i<p.size();i++){
            unordered_map<float,int>u;
            for(int j=0;j<p.size();j++){
                if(i==j)continue;
                float slope=((float)(p[i][1]-p[j][1]))/(float)(p[i][0]-p[j][0]);
                u[slope]++;
                ans=max(ans,u[slope]+1);
            }
        }
        return ans;
    }
};