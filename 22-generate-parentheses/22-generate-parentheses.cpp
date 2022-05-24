class Solution {
public:
    vector<string>res;
    void solve(int o,int c,string s){
        if(o==0&&c==0){
            res.push_back(s);
            return;
        }
        if(o>0)solve(o-1,c+1,s+'(');
        if(c>0)solve(o,c-1,s+')');
    }
    vector<string> generateParenthesis(int n) {
        solve(n,0,"");
        return res;
    }
};