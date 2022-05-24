class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& pts, int k) {
        int ans=INT_MIN;
        //see modtherfucker
        //since its sorted the equation becomes (yi-xi)+(yj+xj)
        int n=pts.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            while(!pq.empty()&&pts[i][0]-pq.top().second>k)pq.pop();
            if(!pq.empty())ans=max(ans,pq.top().first+pts[i][0]+pts[i][1]);
            pq.push({pts[i][1]-pts[i][0],pts[i][0]});
        }
        return ans;
    }
};