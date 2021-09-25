// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

class Solution {
public:
    bool check(vector<int>nums, int d, int threshold){
        int ans=0;
        for(auto num:nums){
            ans+=num/d;
            ans+=(num%d)?1:0;
            if(ans>threshold)return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int h=*max_element(nums.begin(),nums.end()),l=1;
        int res=-1;
        while(h>=l){
            int mid=l+(h-l)/2;
            if(check(nums,mid,threshold)){
                res=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
};