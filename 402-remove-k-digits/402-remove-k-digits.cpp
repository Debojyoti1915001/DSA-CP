class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>stk;
        for(auto c:num){
            while(!stk.empty()&&k>0&&c<stk.top()){
                stk.pop();
                k--;
            }
            if(!stk.empty()||c!='0')stk.push(c);
        }
        while(!stk.empty()&&k--){
            stk.pop();
        }
        if(stk.size()==0)return "0";
        string ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};