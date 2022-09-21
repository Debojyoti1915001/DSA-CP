class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        int e=0;
        for(auto &i:nums){
            if(i%2==0)e+=i;
        }
        for(auto &i:queries){
            if((nums[i[1]]+i[0])%2==0){
                if(nums[i[1]]%2){
                    e+=nums[i[1]]+i[0];
                }else 
                    e+=i[0];
            }else{
                if(nums[i[1]]%2==0){
                    e-=nums[i[1]];
                }
            }
            nums[i[1]]=nums[i[1]]+i[0];
            
            ans.push_back(e);
        }
        return ans;
    }
};