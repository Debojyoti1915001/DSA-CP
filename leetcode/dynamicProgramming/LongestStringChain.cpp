// https://leetcode.com/problems/longest-string-chain/


class Solution {
public:
    static bool comp(string &a,string &b){
        return a.length()<b.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        //strore the results in a unordered map
        unordered_map<string,int>dp;
        int ans=1;
        for(auto word:words){
            for(int i=0;i<word.size();i++){
                string pre=word.substr(0,i)+word.substr(i+1);
                //try to find in map
                dp[word]=max(dp[word],dp.find(pre)!=dp.end()?dp[pre]+1:1);
            }
            ans=max(dp[word],ans);
        }
        return ans;
    }
};