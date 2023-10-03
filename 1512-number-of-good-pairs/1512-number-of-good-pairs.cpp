class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto &i:nums){
            m[i]++;
        }
        int ans=0;
        for(auto &i:m){
            ans+=((i.second-1)*(i.second))/2;
        }
        return ans;
    }
};