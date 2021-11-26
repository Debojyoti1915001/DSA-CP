// https://leetcode.com/problems/word-pattern/

class Solution {
public:
    bool wordPattern(string p, string s) {
        stringstream ss(s);
        string temp;
        map<string,vector<int>>m1;
        map<char,vector<int>>m2;
        int i=0;
        vector<string>v;
        while(getline(ss,temp,' ')){
            m1[temp].push_back(i);
            v.push_back(temp);
            i++;
        }
        for(i=0;i<p.length();i++){
            m2[p[i]].push_back(i);
        }
        vector<int>vis(26);
        for(i=0;i<p.length();i++){
            if(vis[p[i]-'a']==1)continue;
            vis[p[i]-'a']=1;
            if(m1[v[i]]!=m2[p[i]])return false;
        }
        return true;
    }
};