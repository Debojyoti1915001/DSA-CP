class Solution {
public:
    string reverseWords(string s) {
        string ans,w;
        stringstream ss(s);
        while(getline(ss,w,' ')){
            reverse(w.begin(),w.end());
            ans+=w;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};