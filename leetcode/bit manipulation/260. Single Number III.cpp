// https://leetcode.com/problems/single-number-iii/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int all=0;
        for(auto num:nums){
            all^=num;
        }
        int d=0;
        for(int i=0;i<32;i++){
            if(all&(1<<i)){
                d=i;
                break;
            }
        }
        int a=0,b=0;
        for(auto num:nums){
            if(num&(1<<d)){
                a^=num;
            }else{
                b^=num;
            }
        }
        return {a,b};
    }
};