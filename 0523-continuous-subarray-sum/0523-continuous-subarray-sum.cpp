class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int sum=0;
        m[0]=-1;
        for(int i=0;i<nums.size();i++){
            sum=(nums[i]+sum)%k;
            if(m.count(sum)&&i-m[sum]>1)return true;
            if(!m.count(sum))m[sum]=i;
        }
        return false;
    }
};