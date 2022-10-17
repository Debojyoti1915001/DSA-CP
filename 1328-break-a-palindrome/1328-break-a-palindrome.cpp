class Solution {
public:
    string breakPalindrome(string s) {
        string ans;
        for(int i=0;i<s.size();i++){
            if(s.size()%2==1&&i==s.size()/2)continue;
            string cur=s;
            if(cur[i]!='a'){
                cur[i]='a';
            }else if(cur[i]!='z'){
                cur[i]='b';
            }
            if(!ans.size())
                ans=cur;
            else
                ans=min(ans,cur);
        }
        return ans;
    }
};