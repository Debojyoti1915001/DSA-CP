// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    int first(vector<int>v, int t){
        int l=0,h=v.size()-1,ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(v[mid]==t){
                ans=mid;
                h=mid-1;                    
            }
            else if(v[mid]>t){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
    int second(vector<int>v, int t){
        int l=0,h=v.size()-1,ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(v[mid]==t){
                ans=mid;
                l=mid+1;
            }
            else if(v[mid]>t){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int f=first(nums,target);
        int s=second(nums,target);
        return {f,s};
    }
};