class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        vector<int>ans;
        sort(p.begin(),p.end());
        for(auto i:s){
            int cur=lower_bound(p.begin(),p.end(),success/i+((success%i)?1:0))-p.begin();
            cur=p.size()-cur;
            ans.push_back(cur);
        }
        return ans;
    }
};