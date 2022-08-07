class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();
        int ans=0;
        int c1=0;
        int c0=0;    
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                c0=0;
                c0++;
                while(i<s.size()&&s[i]==s[i+1])i++,c0++;
                ans+=min(c1,c0);
            }
            if(s[i]=='1'){
                c1=0;
                c1++;
                while(i<s.size()&&s[i]==s[i+1])i++,c1++;
                ans+=min(c1,c0);
            }
            
        }
        return ans;
    }
};