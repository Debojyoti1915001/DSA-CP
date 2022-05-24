class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        sort(s.begin(),s.end());
        int n=s.size();
        string  ans="";
        for(int i=0;i<s[0].size();i++){
            if(s[0][i]==s[n-1][i])ans+=s[0][i];
            else break;
        }
        return ans;
    }
};