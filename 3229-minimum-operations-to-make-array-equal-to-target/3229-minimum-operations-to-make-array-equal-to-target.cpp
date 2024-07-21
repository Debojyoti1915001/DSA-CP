class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long ans=0;
        for(int i=1;i<nums.size();i++){
            ans+=abs((nums[i]-target[i])-(nums[i-1]-target[i-1]));
        }
        ans+=abs(nums[0]-target[0])+abs(nums[nums.size()-1]-target[nums.size()-1]);
        return ans/2;
    }
};