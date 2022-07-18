class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k)return false;
        unordered_map<string,int>m;
        int cur=0;
        for(int i=0;i<=s.size()-k;i++){
            if(!m[s.substr(i,k)]){
                m[s.substr(i,k)]=1;
                cur++;
            }
        }
        return cur==(1<<k);
    }
};