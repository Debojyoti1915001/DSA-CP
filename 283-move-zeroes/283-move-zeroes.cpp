class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        //if the number is not zero
        //bring it to the correct place
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=0){
                nums[i++]=nums[j];
            }
        }
        for(;i<nums.size();i++)nums[i]=0;
    }
};