class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mi=nums[0],nxt=nums[0];
        int n=nums.size();
        for(int i=1;i<nums.size();i++){
            nxt=max(nxt,nums[i]+i);
            if(i==mi){
                mi=nxt;
            }
            if(mi>=n-1)return true;
        }
        return mi>=n-1;
    }
};