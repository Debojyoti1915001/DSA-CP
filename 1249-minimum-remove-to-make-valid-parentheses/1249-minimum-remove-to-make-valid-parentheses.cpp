class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        stack<int>stk;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                stk.push(i);
            }else if(s[i]==')'){
                if(stk.size())stk.pop();
                else s[i]='0';
            }
        }
        while(stk.size()){
            s[stk.top()]='0';
            stk.pop();
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                ans+=s[i];
            }
        }
        return ans;
    }
};