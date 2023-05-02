class Solution {
public:
    int arraySign(vector<int>& nums) {
        int x=1;
        for(auto i:nums){
            x=x*((i>=0)?1:-1);
            if(i==0)x=x*0;
        }
        return x;
    }
};