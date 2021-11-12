// https://leetcode.com/problems/shuffle-an-array/

class Solution {
public:
    vector<int>original;
    Solution(vector<int>& nums) {
        original=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int>shu=original;
        int n=shu.size();
        for(int i=0;i<n;i++){
            int r=rand()%n;
            swap(shu[i],shu[r]);
        }
        return shu;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */