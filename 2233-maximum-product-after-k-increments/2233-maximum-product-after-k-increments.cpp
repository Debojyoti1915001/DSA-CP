class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod=1e9+7;
        if(nums.size()==1)return (nums[0]+k)%mod;
        priority_queue<int,vector<int>,greater<>>pq;
        for(auto &i:nums)pq.push(i);
        while(k){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            if(a!=b){
                int diff=b-a;
                a+=min(k,diff);
                k-=min(k,diff);   
            }
            if(a==b){
                if(k){
                    a++;
                    k--;
                }if(k){
                    b++;
                    k--;
                }
            }
            pq.push(a);
            pq.push(b);
        }
        long long int ans=1;
        while(pq.size()){
            ans=(ans*pq.top())%mod;
            pq.pop();
        }
        return ans;
    }
};