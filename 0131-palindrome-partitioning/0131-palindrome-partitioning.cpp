class Solution {
public:
    vector<vector<string>>ans;
    bool isPalindrome(string s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    void dfs(string s,int idx,vector<string>&temp){
        if(idx==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(isPalindrome(s.substr(idx,i-idx+1))){
                temp.push_back(s.substr(idx,i-idx+1));
                dfs(s,i+1,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        dfs(s,0,temp);
        return ans;
    }
};