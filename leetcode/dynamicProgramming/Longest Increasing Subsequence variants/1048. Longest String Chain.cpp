class Solution {
public:
    static bool comp(string &a,string &b){
        return a.length()<b.length();
    }
    int longestStrChain(vector<string>& words) {
        //sorting according to length
        sort(words.begin(),words.end(),comp);
        unordered_map<string,int>dp;
        int ans=0;
        for(auto word:words){
            //for each word remove a char one by one and then try to find if that word exist in the map
            for(int i=0;i<word.size();i++){
                string pre=word.substr(0,i)+word.substr(i+1);
                dp[word]=max(dp[word],(dp.count(pre)?dp[pre]+1:1));
            }
            ans=max(ans,dp[word]);
        }
        return ans;
    }
};