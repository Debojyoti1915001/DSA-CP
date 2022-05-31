class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string,int>m;
        int cur=0;
        if(s.size()<k)return false;
        for(int i=0;i<=s.size()-k;i++){
            if(!m[s.substr(i,k)]){
                m[s.substr(i,k)]=1;
                cur++;
            }
        }
        return cur==(1<<k);
    }
};