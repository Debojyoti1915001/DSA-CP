class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>stk;
        for(int i=0;i<s.length();i++){
            if(stk.size()==0)stk.push(s[i]);
            else if(stk.top()!=s[i])stk.push(s[i]);
            else  if(stk.top()==s[i])stk.pop();
        }
        s.clear();
        while(stk.size()){
            s.push_back(stk.top());
            stk.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};