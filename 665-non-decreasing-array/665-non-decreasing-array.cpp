class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){//then there is an issue
                cnt++;
                //             |
                //3 4->3  2 
                //when nums[i-2] is less than current->i then we have to DECRESE nums[i-1] since nums[i-1]>nums[i] CAUSE nums[i-2] and nums[i] are in their right place
                if(i==1||nums[i-2]<=nums[i])nums[i-1]=nums[i];
                //else you have to change nums[i] 
                else nums[i]=nums[i-1];
            }
        }
        return cnt<=1;
    }
};