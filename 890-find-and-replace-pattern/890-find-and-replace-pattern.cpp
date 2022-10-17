class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(auto i:words){
            int f=0;
            map<char,char>m;
            map<char,int>vis;
            for(int j=0;j<i.size();j++){
                if(!m.count(i[j])){
                    if(vis.count(pattern[j])){
                        f=1;
                        break;
                    }else 
                    m[i[j]]=pattern[j];
                    vis[pattern[j]]++;
                }else{
                    if(m[i[j]]!=pattern[j]){
                        f=1;
                        break;
                    }
                }
            }
            if(!f)ans.push_back(i);
        }
        return ans;
    }
};