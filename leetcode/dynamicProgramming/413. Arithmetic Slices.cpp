class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return 0;
        int c=0,ans=0,prev=nums[1]-nums[0];
        for(int i=2;i<n;i++){
            int diff=nums[i]-nums[i-1];
            if(diff==prev)c++;
            else{
                ans+=((c)*(c+1))/2;
                c=0;
                prev=diff;
            }
        }
        if(c)ans+=((c)*(c+1))/2;
        return ans;
    }
};