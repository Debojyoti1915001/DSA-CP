class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0,sum=0;
        int i=0,j=0;
        unordered_map<int,int>m;
        int n=nums.size();
        while(j<n){
            m[nums[j]]++;
            sum+=nums[j];
            while(i<=j&&m[nums[j]]>1){
                m[nums[i]]--;
                sum-=nums[i];
                i++;
            }
            j++;
            ans=max(ans,sum);
        }
        return ans;
    }
};