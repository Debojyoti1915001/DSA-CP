// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo=0,hi=height.size()-1;
        int ans=0;
        while(lo<hi){
            int ar=min(height[lo],height[hi])*(hi-lo);
            ans=max(ans,ar);
            if(height[lo]<height[hi]){
                lo++;
            }else{
                hi--;
            }
        }
        return ans;
    }
};