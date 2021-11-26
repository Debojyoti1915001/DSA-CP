// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

class Solution {
public:
    int minimumDeletions(string s) {
        int a=0,b=0,ca=0,cb=0;
        for(auto c:s){
            if(c=='a')ca++;
            else cb++;
        }
        int n=s.length();
        int ans=ca;
        for(int i=0;i<n;i++){
            if(s[i]=='a')a++;
            else b++;
            ans=min(ans,ca-a+b);
        }
        return ans;
    }
};