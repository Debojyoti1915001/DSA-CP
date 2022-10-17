class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        unordered_set<string>ban(banned.begin(),banned.end());
        for(auto &i:p)i=(isalpha(i)?tolower(i):' ');
        unordered_map<string,int>cnt;
        stringstream ss(p);
        int highest=0;
        string ans="",w;
        while(ss>>w){
            cnt[w]++;
            if( cnt[w]>highest && !ban.count(w) ){
                highest=cnt[w];
                ans=w;
            }
        }
        return ans;
    }
};