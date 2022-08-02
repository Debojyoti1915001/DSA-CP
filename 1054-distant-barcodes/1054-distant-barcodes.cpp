class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int>ans;
        map<int,int>m;
        for(auto &i:barcodes){
            m[i]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto i:m){
            pq.push({i.second,i.first});
        }
        while(pq.size()>1){
            auto [a,b]=pq.top();
            pq.pop();
            a--;
            ans.push_back(b);
            auto [c,d]=pq.top();
            pq.pop();
            c--;
            ans.push_back(d);
            if(a)
                pq.push({a,b});
            if(c)
                pq.push({c,d});
        }
        if(pq.size()==1){
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};