// https://leetcode.com/problems/find-common-characters/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>cnt(26);
        for(char c:words[0]){
            cnt[c-'a']++;
        }
        for(auto word:words){
            vector<int>cnt1(26);
            for(char c:word){
                cnt1[c-'a']++;
            }
            for(int i=0;i<26;i++)cnt[i]=min(cnt[i],cnt1[i]);
        }
        vector<string>ans;
        for(int i=0;i<26;i++){
            if(cnt[i]>0){
                string temp="";
                temp.push_back(i+'a');
                while(cnt[i]--)
                ans.push_back(temp);
            }
        }
        return ans;
    }
};