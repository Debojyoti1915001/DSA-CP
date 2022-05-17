class Solution {
public:
    static bool comp(string a,string b){
        return a.length()<b.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int ans=1;
        unordered_map<string,int>dp;
        for(auto word:words){
            for(int i=0;i<word.size();i++){
                string pre=word.substr(0,i)+word.substr(i+1);
                dp[word]=max(dp[word],dp[pre]+1);   
            }
            ans=max(ans,dp[word]);
        }
        return ans;
    }
};