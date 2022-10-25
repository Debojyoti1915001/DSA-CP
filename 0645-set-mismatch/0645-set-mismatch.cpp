class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int f=-1,s=-1;
        for(int i:nums){
            int idx=abs(i)-1;
            // cout<<idx<<" ";
            if(nums[idx]<0)f=abs(i);
            else nums[idx]=-1*nums[idx];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)s=i+1;
        }   
        return {f,s};
    }
};