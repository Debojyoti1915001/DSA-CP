class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        // brute force
        // int ans=0;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i;j<nums.size()&&nums[i]%k==0;j++){
        //         nums[i]=__gcd(nums[i],nums[j]);
        //         if(nums[i]==k)ans++;
        //     }
        // }
        // return ans;
        //have a count of the previous gcd's
        unordered_map<int,int>gcd;
        int res=0;
        for(auto &i:nums){
            unordered_map<int,int>gcd1;
            if(i%k==0){
                ++gcd[i];
                for(auto [num,cnt]:gcd){
                    gcd1[__gcd(num,i)]+=cnt;
                }
            }
            res+=gcd1[k];
            swap(gcd,gcd1);
        }
        return res;
    }
};