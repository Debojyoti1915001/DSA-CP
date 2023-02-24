class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        //max heap
        priority_queue<long long int>pq;
        long long int mn=INT_MAX;//minimum that is present in the pq
        //so we have inserted elements the max value of which is possible
        //if it is odd we can multiply only one time
        //if it is even we can just divide it bu two
        for(auto &num:nums){
            num=(num%2==1)?num*2:num;
            pq.push(num);
            mn=min(mn,(long long int)num);
        }
        //we will always decreace the value and the minimum value possible
        long long int ans=INT_MAX;
        while (pq.top() % 2 == 0) {
        ans = min(ans, pq.top() - mn);
        mn = min(mn, pq.top() / 2);
        pq.push(pq.top() / 2);
        pq.pop();
    }
    return min(ans, pq.top() - mn);
    }
};