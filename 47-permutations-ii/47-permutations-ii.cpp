class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        set<vector<int>> st;
        vector<int> temp = nums;
        do
        {
            next_permutation(temp.begin(), temp.end());
            st.insert(temp);
        } while (temp != nums);
        vector<vector<int>> ans;
        for (auto it: st)
            ans.push_back(it);
        return ans;
    }
};