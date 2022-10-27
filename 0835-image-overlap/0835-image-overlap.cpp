class Solution {
public:
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int res=0;
        int n=a.size();
        vector<pair<int,int>>A,B;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==1)A.push_back({i,j});
                if(b[i][j]==1)B.push_back({i,j});
            }
        }
        map<pair<int,int>,int>c;
        for(auto &[ai,aj]:A){
            for(auto &[bi,bj]:B){
                c[{ai-bi,aj-bj}]++;
                res=max(res,c[{ai-bi,aj-bj}]);
            }
        }
        return res;
    }
};