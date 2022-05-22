class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0,cur=0;
        unordered_map<int,int>m;
        for(auto num:nums){
            cur+=num;
            if((cur%k+k)%k==0)ans++;
            if(m[(cur%k+k)%k]>0)ans+=m[(cur%k+k)%k];
            m[(cur%k+k)%k]++;
        }
        return ans;
    }
};