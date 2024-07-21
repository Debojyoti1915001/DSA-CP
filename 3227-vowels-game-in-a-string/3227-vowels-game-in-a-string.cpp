class Solution {
public:
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
            return true;
        }
        return false;
    }
    bool doesAliceWin(string s) {
        int o1=0,o2=0,e=0;
        int len=0;
        for(int i=0;i<=s.size();i++){
            if(i!=s.size()&&isVowel(s[i])){
                len++;
            }else if((i==s.size()&&len!=0)||len!=0){
                if(len%2==0)e++;
                else if(len==1){
                    o1++;
                }else{
                    o2++;
                }
                len=0;
            }
        }
        if(o1==0&&o2==0&&e==0)return false;
        return true;
    }
};