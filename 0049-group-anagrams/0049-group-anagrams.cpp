class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>m;
        vector<vector<string>>ans;
        for(auto s:strs){
            string temp=s;
            sort(temp.begin(),temp.end());
            m[temp].push_back(s);
        }
        for(auto itr:m){
            ans.push_back(itr.second);
        }
        return ans;
    }
};