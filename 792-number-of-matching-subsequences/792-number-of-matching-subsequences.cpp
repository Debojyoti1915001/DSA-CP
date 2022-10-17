class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<string>>m;
        for(auto w:words){
            m[w[0]].push_back(w);
        }
        int ans=0;
        for(auto i:s){
            if(m[i].size()==0)continue;
            vector<string>v=m[i];
            m.erase(i);
            for(auto j:v){
                if(j.size()==1)ans++;
                else m[j[1]].push_back(j.substr(1));
            }
        }
        return ans;
    }
};