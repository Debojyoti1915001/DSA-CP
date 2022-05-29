class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int res = 0, sum = 0;
        unordered_set<int> sets;
        sets.insert(0);
        for(int x : nums) {
            sum += x;

            if(sets.count(sum - target)) {
                //restart, clear whatever was recorded
                ++res;
                sets= {0};
                sum = 0;
            } else{
                sets.insert(sum);
            }
        }
        return res;
    }
};