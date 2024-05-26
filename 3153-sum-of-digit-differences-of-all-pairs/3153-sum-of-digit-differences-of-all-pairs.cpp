class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        vector<vector<int>>mp(to_string(nums[0]).size(),vector<int>(10));
        for(auto &i:nums){
            string s=to_string(i);
            for(int j=0;j<s.size();j++){
                mp[j][s[j]-'0']++;
            }
        }
        long long ans=0;
        for(int i=0;i<to_string(nums[0]).size();i++){
            for(int j=0;j<10;j++){
                for(int k=j+1;k<10;k++){
                    int cntj=mp[i][j];
                    int cntk=mp[i][k];
                    ans+=(cntj*cntk);
                }   
            }
        }
        return ans;
    }
};