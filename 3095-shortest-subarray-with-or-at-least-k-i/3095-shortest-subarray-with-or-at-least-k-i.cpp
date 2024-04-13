class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i=0,j=0;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int cur=0;
            for(int j=i;j<nums.size();j++){
                cur|=nums[j];
                if(cur>k||cur==k){
                    ans=min(ans,j-i+1);
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};