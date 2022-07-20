class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        map<char,vector<string>>mp;
        for(string &word:words){
            mp[word[0]].push_back(word);
        }
        for(char c:s){
            if(mp[c].size()){
                vector<string> wrds=mp[c];
                 mp.erase(c);
                for (string& word : wrds) {
                    if (word.size() == 1) {
                        ans++;
                    }
                    else {
                        mp[word[1]].push_back(word.substr(1));
                    }
                }
            }
        }
        return ans;
    }
};