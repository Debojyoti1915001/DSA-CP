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
            sum+=old; 
            if(old==0&&sum!=1 ) return false;
            pq.pop();
            pq.push(old);
            
        }
        return true;
    }
};