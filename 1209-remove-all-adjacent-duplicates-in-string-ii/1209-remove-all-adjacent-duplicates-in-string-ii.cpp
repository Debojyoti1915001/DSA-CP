class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>stk;
        for(int i=0;i<s.length();i++){
            if(stk.size()==0)stk.push({s[i],1});
            else if(stk.top().first==s[i]){
                int temp=stk.top().second;
                stk.pop();
                if(temp+1!=k)
                stk.push({s[i],temp+1});
            }else if(stk.top().first!=s[i]){
             stk.push({s[i],1});
            }
        }
        s.clear();
        while(stk.size()){
            int cnt=stk.top().second;
            while(cnt--)
            s.push_back(stk.top().first);
            stk.pop();
        }
        reverse(s.begin(),s.end());
        return s;
        
    }
};