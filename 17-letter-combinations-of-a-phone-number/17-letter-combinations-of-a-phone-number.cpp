class Solution {
public:
    void solve(int i,int n,vector<string>&v,string dp[], string &p,string s){
        if(i>=n){
            v.push_back(p);
            return;
        }
        for(int j=0; j<dp[s[i]-'0'].size(); j++){
            p+=dp[s[i]-'0'][j];
            solve(i+1,n,v,dp,p,s);
            p.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string s) {
        
        string dp[10];
        dp[2]="abc";
        dp[3]="def";
        dp[4]="ghi";
        dp[5]="jkl";
        dp[6]="mno";
        dp[7]="pqrs";
        dp[8]="tuv";
        dp[9]="wxyz";
        vector<string> ans;
        string temp="";
        if(s.length()==0)return ans;
        solve(0,s.length(),ans,dp,temp,s);
        return ans;
    }
};