class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=0,mx=0,mn=0;
        for(auto num:nums){
            mx=max(mx+num,num);
            mn=min(mn+num,num);
            ans=max({ans,mx,abs(mn)});
        }
        return ans;
    }
};