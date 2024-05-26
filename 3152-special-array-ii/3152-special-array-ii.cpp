class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<int>conv(1);
        for(int i=1;i<nums.size();i++){
                conv.push_back(conv.back()+(nums[i]%2==nums[i-1]%2));
        }
        for(auto &i:queries){
            ans.push_back(conv[i[0]]==conv[i[1]]);
        }
        return ans;
    }
};