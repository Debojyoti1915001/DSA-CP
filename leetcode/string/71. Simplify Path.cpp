// https://leetcode.com/problems/simplify-path/

class Solution {
public:
    string simplifyPath(string path) {
        string res="",tmp;
        vector<string>s;
        stringstream ss(path);
        while(getline(ss,tmp,'/')){
            if(tmp=="."||tmp=="")continue;
            else if(tmp==".."&&s.size())s.pop_back();
            else if(tmp!="..")s.push_back(tmp);
        }
        for(auto t:s){
            res+="/"+t;
        }
        return res.size()==0?"/":res;
    }
};