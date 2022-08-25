class Solution {
public:
    bool canConstruct(string a, string b) {
        vector<int>cnt(26),cnt1(26);
        for(auto &i:a)cnt[i-'a']++;
        for(auto &i:b)cnt1[i-'a']++;
        for(int i=0;i<26;i++){
            if(cnt1[i]<cnt[i])return false;
        }
        return true;
    }
};