// https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    //run NGE two times 
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>stack,res(n,-1);
        for(int i=0;i<n*2;i++){
            while(stack.size()&&nums[stack.back()]<nums[i%n]){
                res[stack.back()]=nums[i%n];
                stack.pop_back();
            }
            stack.push_back(i%n);
        }
        return res;
    }
};