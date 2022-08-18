#define pp pair<int,int>
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod=1e9+7;
        //pair to store the current min and the index
        priority_queue<pp,vector<pp>,greater<pp>>pq;//to find the minimum at the top min heap
        for(int i=0;i<n;i++){
            pq.push({nums[i],i+1});
        }
        int ans=0,c=0;
        for(int i=1;i<=right;i++){
            auto t=pq.top();
            pq.pop();
            if(i>=left){
                ans=(ans+t.first)%mod;
            }
            if(t.second<n){
                t.first+=nums[t.second++];
                pq.push(t);
            }
            
        }
        return ans;
    }
};