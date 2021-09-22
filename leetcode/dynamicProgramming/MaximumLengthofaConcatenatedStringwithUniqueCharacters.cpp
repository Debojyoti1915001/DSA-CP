// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

class Solution {
public:
    bool isUnique(string s){
        if(s.length()>26)return false;
        vector<int>used(26);
        for(int i=0;i<s.length();i++){
            if(used[s[i]-'a'])return false;
            used[s[i]-'a']=1;
        }
        return true;
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        vector<string>res{""};
        for(auto &a:arr){
            if(!isUnique(a))continue;
            vector<string>genList;
            for(auto b:res){
                string gen=a+b;
                if(isUnique(gen))genList.push_back(gen);
            }
            res.insert(res.end(),genList.begin(),genList.end());
        }
        int ans=0;
        for(string str:res){
            ans=max(ans,(int)str.length());
        }
        return ans;
    }
};
