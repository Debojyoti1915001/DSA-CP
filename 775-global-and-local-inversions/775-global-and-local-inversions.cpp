class Solution {
public:
    #define MAX 200005
    long long bit[MAX];
    long long query(int indx) {
        long long sum = 0;
        while (indx) {
            sum += bit[indx];
            indx -= (indx & -indx);
        }
        return sum;
    }

    void update(int indx, int x) {
        assert(indx != 0);
        while (indx < MAX) {
            bit[indx] += x;
            indx += (indx & -indx);
        }
    }
    bool isIdealPermutation(vector<int>& nums) {
        for(int &i:nums)i+=1;
        int ans=0;
        for(int i=nums.size()-1;i>=0;i--){
            ans+=query(nums[i]-1);
            update(nums[i],1);
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i])ans--;
        }
        return ans==0;    
    }
};