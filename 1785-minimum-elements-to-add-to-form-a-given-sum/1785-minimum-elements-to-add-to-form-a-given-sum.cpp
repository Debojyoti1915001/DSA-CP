class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        return (abs(accumulate(nums.begin(),nums.end(),(long long int)0)-goal))/limit+((((abs(accumulate(nums.begin(),nums.end(),(long long int)0)-goal))%limit)==0)?0:1);
    }
};