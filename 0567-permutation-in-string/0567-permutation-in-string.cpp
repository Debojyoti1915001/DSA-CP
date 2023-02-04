class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>cnt(26),cnt1(26);
        for(auto c:s1){
            cnt[c-'a']++;
        }
        int i=0,j=0;
        int k=s1.size();
        while(j<s2.size()){
            cnt1[s2[j]-'a']++;
            if(j-i+1<k){
                j++;
            }else{
                if(cnt==cnt1)return true;
                cnt1[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};