class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            int k = nums[i]%n;
            nums[k]+=n;
        }
        int m =0;
        int ind =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>m){
                m = nums[i]; 
                ind = i; 
            }
        }
        return ind;
    }
};