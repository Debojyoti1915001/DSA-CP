#define pp pair<int,int>
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>res;
        int n=mat.size();
        int m=mat[0].size();
        priority_queue<pp,vector<pp>,greater<>>pq;
        for(int i=0;i<mat.size();i++){
            int c=0;
            for(auto j:mat[i]){
                c+=j==1;
            }
            pq.push({c,i});
        }
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};