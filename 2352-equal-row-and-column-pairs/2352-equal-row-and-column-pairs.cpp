class Solution {
public:
    int equalPairs(vector<vector<int>>& g) {
        map<vector<int>,int>cnt;
        for(int j=0;j<g[0].size();j++){
            vector<int>cur;
            for(int i=0;i<g.size();i++){
                cur.push_back(g[i][j]);
            }
            cnt[cur]++;
        }
        int ans=0;
        for(auto i:g){
            ans+=cnt[i];
        }
        return ans;
    }
};