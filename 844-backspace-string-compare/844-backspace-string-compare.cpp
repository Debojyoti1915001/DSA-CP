class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>a,b;
        for(int i=0;i<s.length();i++){
            if(a.size()&&s[i]=='#'){
                a.pop();
            }else if(s[i]!='#'){
                a.push(s[i]);
            }
        }
        for(int i=0;i<t.length();i++){
            if(b.size()&&t[i]=='#'){
                b.pop();
            }else if(t[i]!='#'){
                b.push(t[i]);
            }
        }
        return a==b;
    }
};