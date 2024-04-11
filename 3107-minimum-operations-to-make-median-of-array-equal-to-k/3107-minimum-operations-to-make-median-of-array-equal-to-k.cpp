class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<nums.size()/2;i++){
            ans+=max(0,nums[i]-k);
        }
        for(int i=nums.size()/2+1;i<nums.size();i++){
            ans+=max(0,k-nums[i]);
        }
        return ans+abs(k-nums[nums.size()/2]);
    }
};