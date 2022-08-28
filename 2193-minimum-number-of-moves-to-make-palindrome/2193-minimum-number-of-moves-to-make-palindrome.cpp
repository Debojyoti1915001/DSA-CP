class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int ans=0;
        vector<int>cnt(26);
        for(auto &i:s)cnt[i-'a']++;
        int odd=0;
        for(int i=0;i<26;i++){
            if(cnt[i]%2)odd++;
        }
        if(odd>1)return -1;
        while(s.size()){
            int i=s.find(s.back());
            if(i==s.size()-1)ans+=i/2;
            else{
                ans+=i;
                s.erase(i,1);
            }
            s.pop_back();
        }
        return ans;
    }
};