class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s=to_string(n);
        int sz=s.size(),lim=s.size();
        for(int i=sz-1;i>0;i--){
            if(s[i-1]>s[i])lim=i,s[i-1]-=1;
        }
        for(int i=lim;i<sz;i++)s[i]='9';
        return stoi(s);
    }
};