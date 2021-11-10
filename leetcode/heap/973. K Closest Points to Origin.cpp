// https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>maxh;
        for(auto p:points){
            maxh.push({p[0]*p[0]+p[1]*p[1],{p[0],p[1]}});
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        vector<vector<int>>ans;
        while(maxh.size()){
            pair<int,int>p=maxh.top().second;
            ans.push_back({p.first,p.second});
            maxh.pop();
        }
        return ans;
    }
};