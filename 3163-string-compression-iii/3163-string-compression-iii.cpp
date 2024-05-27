class Solution {
public:
    string compressedString(string word) {
        string ans="";
        char c=word[0];
        int cnt=0;
        for(auto &i:word){
            if(c==i){
                cnt++;
            }
            if(c!=i||cnt==9){
                if(cnt){
                    ans+=to_string(cnt);
                    ans+=c;
                }
                c=i;
                if(cnt==9)cnt=0;
                else cnt=1;
            }
        }
        if(cnt){
            ans+=to_string(cnt);
            ans+=c;
        }
        return ans;
    }
};