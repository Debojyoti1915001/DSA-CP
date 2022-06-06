class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>cnt{0,0,0};
        int res=0;
        int i=0,j=0,n=s.length();
        while(j<n){
            cnt[s[j]-'a']++;
            while(cnt[0]&&cnt[1]&&cnt[2]){
                cnt[s[i++]-'a']--;
            }
            // all the string earlier than i will be counted
            res+=i;
            j++;
        }
        return res;
    }
};