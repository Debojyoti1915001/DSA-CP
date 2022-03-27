class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(auto c:s){
            if(c=='('||c=='{'||c=='[')stk.push(c);
            else if(stk.empty())return false;
            else if(c==')'){
                if(stk.top()!='(')return false;
                stk.pop();
            }else if(c==']'){
                if(stk.top()!='[')return false;
                stk.pop();
            }else if(c=='}'){
                if(stk.top()!='{')return false;
                stk.pop();
            }
        }
        return stk.size()==0;
        
    }
};