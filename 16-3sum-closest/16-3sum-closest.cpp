class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=nums[0] + nums[1] + nums[2];
        for(int i=0;i<n;i++){
            int l=i+1,h=n-1;
            while(l<h){
                int sum=nums[i]+nums[l]+nums[h];
                if (sum == target) return target;
                if(abs(ans - target)>abs(sum-target))ans=sum;
                else if(sum>target)h--;
                else l++;
            }
        }
        return ans;
    }
};