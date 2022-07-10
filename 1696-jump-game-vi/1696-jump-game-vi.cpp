class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        int n=nums.size();
        int cur=0;
        for(int i=n-1;i>=0;i--){
            while(pq.size()&&pq.top().second>i+k)pq.pop();
            cur=nums[i]+(pq.size()==0?0:pq.top().first);
            pq.push({cur,i});
           
        }
        return cur;
    }
};