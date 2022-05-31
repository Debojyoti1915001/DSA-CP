class Solution {
public:
    int minDeletions(string s) {
        //lets find the number of elements we can keep
        //think opposite
        vector<int>cnt(26);
        for(auto c:s){
            cnt[c-'a']++;
        }
        int keep=0,prev=INT_MAX;
        //we want to have the max number of keeps so sort it
        sort(cnt.begin(),cnt.end(),greater<>());
        for(auto c:cnt){
            if(c&&prev){
                //remember what is the max value we can keep of the next char is prev-1
                //so find the minimum between the current count and prev -1
                prev=min(prev-1,c);
                keep+=prev;
            }
        }
        return s.size()-keep;
    }
};