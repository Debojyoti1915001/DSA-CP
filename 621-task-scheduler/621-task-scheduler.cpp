class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>cnt(26);//to store the count of each character in the string
        for(auto t:tasks){
            cnt[t-'A']++;
        }
        priority_queue<int>pq;//max heap
        for(auto c:cnt){
            if(c)pq.push(c);
        }
        int res=0;
        while(!pq.empty()){
            vector<int>temp;
            int time=0;
            for(int i=0;i<n+1&&pq.size();i++){
                int t=pq.top();
                pq.pop();
                temp.push_back(t-1);
                time++;
            }
            for(auto t:temp){
                if(t)pq.push(t);
            }
            res+=pq.size()?n+1:time;
        }
        return res;
    }
};