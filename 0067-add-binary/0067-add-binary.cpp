class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length()<b.length())return addBinary(b,a);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string ans="";
        int i=0,c=0;
        while(i<a.length()){
            int cur=0;
            if(i<b.length())cur=a[i]+b[i]+c-'0'-'0';
            else cur=a[i]+c-'0';
            if(cur==0){
                ans+='0';
            }else if(cur==1){
                ans+='1';
                c=0;
            }else if(cur==2){
                ans+='0';
                c=1;
            }else{
                ans+='1';
                c=1;
            }
            i++;
        }
        if(c){
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};