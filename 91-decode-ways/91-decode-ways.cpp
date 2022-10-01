class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if(n==0)return 1;
        int t[n+1];
        memset(t,0,sizeof(t));
        t[0]=1;
        if(s[0]=='0'){
            t[1]=0;
        }else{
            t[1]=1;
        }
        for(int i=2;i<=n;i++){
            if(s[i-1]!='0'){
                t[i]=t[i-1];
            }
            if(s[i-2]!='0'){
                int ten=(s[i-2]-'0')*10;
                int one=(s[i-1]-'0');
                if(ten+one<=26){
                    t[i]+=t[i-2];
                }
            }
        }
        return t[n];
    }
};