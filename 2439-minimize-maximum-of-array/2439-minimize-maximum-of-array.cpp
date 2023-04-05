class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int ans=0;
        long long int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans=max(ans,(int)ceil(double(sum)/(i+1)));
        }
        return ans;
    }
};