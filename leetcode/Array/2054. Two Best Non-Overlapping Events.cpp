// https://leetcode.com/problems/two-best-non-overlapping-events/

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& e) {
        int res=0;
        int maxValue=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        sort(e.begin(),e.end());
        for(auto ev:e){
            while(!pq.empty()&&pq.top().first<ev[0]){
                maxValue=max(maxValue,pq.top().second);
                pq.pop();
            }
            res=max(res,maxValue+ev[2]);
            pq.push({ev[1],ev[2]});
        }
        return res;
    }
};