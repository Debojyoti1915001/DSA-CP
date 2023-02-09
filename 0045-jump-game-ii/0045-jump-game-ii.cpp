class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)return 0;
        int nxt=nums[0],mi=nums[0],res=1;
        for(int i=1;i<nums.size();i++){
            if(mi>=nums.size()-1)return res;
            nxt=max(nxt,nums[i]+i);
            if(mi==i){
                res++;
                mi=nxt;
            }
        }
        return res;
    }
};