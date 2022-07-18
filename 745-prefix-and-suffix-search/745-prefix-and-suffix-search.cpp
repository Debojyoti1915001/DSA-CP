class WordFilter {
public:
    unordered_map<string,int>m;
    WordFilter(vector<string>& words) {
        for(int k=0;k<words.size();k++){
            string w=words[k];
            for(int i=1;i<=w.size();i++){
                string pre=w.substr(0,i);
                for(int j=0;j<w.size();j++){
                    string post=w.substr(j,w.size());
                    m[pre+"|"+post]=k+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return m[prefix+"|"+suffix]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */