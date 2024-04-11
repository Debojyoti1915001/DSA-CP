class Solution {
public:
    string getSmallestString(string s, int k) {
        for(int i=0;i<s.size()&&k;i++){
            if(min(s[i]-'a',26-(s[i]-'a'))<=k){
                k-=min(s[i]-'a',26-(s[i]-'a'));
                s[i]='a';
            }else{
                s[i]-=k;
                k=0;
            }
        }
        return s;
    }
};