class Solution {
public:
    string simplifyPath(string path) {
        //result and cur to be used in getline
        string res,cur;
        vector<string>stk;
        stringstream ss(path);
        while(getline(ss,cur,'/')){
            cout<<cur<<endl; 
            //since . or space means current directory
            if(cur=="."||cur=="")continue;
            // ".." means up
            else if(cur==".."){if(stk.size())stk.pop_back();}
            //or this
            else stk.push_back(cur);
        }
        for(auto c:stk){
            res+="/"+c;
        }
        return res.size()==0?"/":res;
    }
};