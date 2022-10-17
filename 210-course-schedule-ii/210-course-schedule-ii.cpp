class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        queue<int>q;
        vector<int>in(n);
        vector<vector<int>>g(n);
        for(auto i:p){
            g[i[1]].push_back(i[0]);
            in[i[0]]++;
        }
        vector<int>res;
        for(int i=0;i<n;i++)if(in[i]==0){
            q.push(i);
            res.push_back(i);
        }
        while(q.size()){
            int t=q.front();
            q.pop();
            for(auto &i:g[t]){
                in[i]--;
                if(in[i]==0){
                    q.push(i);
                    res.push_back(i);
                }
            }
            
        }
        if(res.size()!=n)return {};
        return res;
    }
};