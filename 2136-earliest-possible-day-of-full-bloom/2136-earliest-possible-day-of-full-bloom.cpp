class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        vector<pair<int,int>>v;
        int n=p.size();
        for(int i=0;i<n;i++){
            v.push_back({g[i],p[i]});
        }
        sort(begin(v),end(v));
        int ans=0;
        for(auto &[gr,pl]:v){
            ans=max(ans,gr)+pl;
        }
        return ans;
    }
};