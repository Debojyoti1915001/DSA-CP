// https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1=INT_MAX,c2=INT_MAX;
        for(auto num:nums){
            if(num<=c1){
                c1=num;
            }else if(num<=c2){
                c2=num;
            }else{
                return true;
            }
        }
        return false;
    }
};