class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pq;
        int ans=INT_MIN;
        for(auto p:points){
            while(pq.size()&&p[0]-pq.top().second>k)pq.pop();
            if(pq.size())ans=max(ans,pq.top().first+p[0]+p[1]);
            pq.push({p[1]-p[0],p[0]});
        }
        return ans;
    }
};