class Solution {

public:
    unordered_map<string, bool> dp;

    bool isConcatenated(string word, unordered_set<string> &st) {
        if( dp.find(word) != dp.end() ) 
            return dp[word];

        int len = word.length();
        
        for (int i = 0; i < len; i++)
        {
            string prefix = word.substr(0, i+1);
            string suffix = word.substr(i+1);

            if( (st.find(prefix) != st.end() && isConcatenated(suffix, st)) ||
            (st.find(prefix) != st.end() && st.find(suffix) != st.end()) ) 
                return dp[word] = true;
        }

        return dp[word] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(begin(words), end(words));
        vector<string> result;
        dp.clear();
        
        for (auto &&word : words)
        {
            if(isConcatenated(word, st)) {
                result.push_back(word);
            }
        }
        
        return result;
    }

};