class Solution {
public:
    int minFlips(string s) {
        int sz=s.size();
        int s0=0,s1=0,res=INT_MAX;
        for(int i=0;i<2*sz;i++){
            s0+=s[i%sz]==('0'+i%2);
            s1+=s[i%sz]==('0'+(1-i%2));
            if(i>=sz-1){
                if(i>=sz){
                    s0-=s[i-sz]==('0'+(i-sz)%2);
                    s1-=s[i-sz]==('0'+(1-(i-sz)%2));
                }
                res=min({s0,s1,res});
            }
        }
        return res;
    }
};