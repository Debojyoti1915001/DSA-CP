class Solution {
public:
    bool isPossible(vector<int>& t) {
        priority_queue<long long>pq;
        long long sum=0;
        for(auto &i:t){
            pq.push(i);
            sum+=i;
        }
        while(pq.top()!=1){
           sum -= pq.top();
            if(sum == 0 || sum >= pq.top()) return false;
            int old=pq.top()%sum;
             if(sum!=1&& old <1 ) return false;
            pq.pop();
            pq.push(old);
            sum+=old;
        }
        return true;
    }
};