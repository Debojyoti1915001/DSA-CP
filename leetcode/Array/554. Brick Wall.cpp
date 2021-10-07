// https://leetcode.com/problems/brick-wall/

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int>m;
        for(int i=0;i<wall.size();i++){
            int sum=wall[i][0];
            for(int j=1;j<wall[i].size();j++){
                m[sum]++;
                sum+=wall[i][j];
            }
        }
        int ans=wall.size();
        for(auto c:m){
            ans=min(ans,(int)wall.size()-(int)c.second);
        }
        return ans;
    }
};
