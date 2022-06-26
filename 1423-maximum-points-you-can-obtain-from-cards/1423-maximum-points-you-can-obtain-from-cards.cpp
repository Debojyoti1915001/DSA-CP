class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int ans=0;
        for(int i=0;i<k;i++)ans+=v[i];
        int val=ans;
        for(int i=0;i<k;i++){
            val=val-(v[k-i-1])+v[v.size()-1-i];
            ans=max(ans,val);
        }
        return ans;
    }
};