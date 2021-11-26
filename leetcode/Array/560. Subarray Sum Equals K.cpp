// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int cur=0,ans=0;
        for(auto num:nums){
            cur+=num;
            if(cur==k)ans++;
            if(mp[cur-k]>0){
                ans+=mp[cur-k];
            }
            mp[cur]++;
        }
        return ans;
    }
};