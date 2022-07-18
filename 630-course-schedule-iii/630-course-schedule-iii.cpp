class Solution {
public:
    int scheduleCourse(vector<vector<int>>& c) {
        sort(c.begin(),c.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        priority_queue<int>pq;//max heap
        int sum=0;
        for(auto &i:c){
            sum+=i[0];
            pq.push(i[0]);
            if(sum>i[1]){
                sum-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};