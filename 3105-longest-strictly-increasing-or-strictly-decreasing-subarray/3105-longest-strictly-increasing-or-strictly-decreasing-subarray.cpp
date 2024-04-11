class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=0,dec=0,mx=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                dec=0;
                inc++;
                mx=max(mx,inc);
            }else if(nums[i-1]>nums[i]){
                inc=0;
                dec++;
                mx=max(mx,dec);
            }else{
                inc=0;
                dec=0;
            }
        }
        return mx+1;
    }
};