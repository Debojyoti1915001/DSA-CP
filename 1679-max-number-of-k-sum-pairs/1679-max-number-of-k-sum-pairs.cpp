class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int ans=0;
        int sz=nums.size();
        for(int i=0;i<sz;i++){
            if(m[k-nums[i]]>0){
                ans++;  
                m[k-nums[i]]--;
            }else{
                m[nums[i]]++;
            }
        }
        return ans;
    }
};