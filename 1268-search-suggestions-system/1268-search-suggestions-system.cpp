class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& p, string s) {
        vector<vector<string>>res;
        map<string,vector<string>>m;
        for(auto c:p){
            for(int i=1;i<=c.size();i++){
                if(m[c.substr(0,i)].size()<=3)
                m[c.substr(0,i)].push_back(c);
                sort(m[c.substr(0,i)].begin(),m[c.substr(0,i)].end());
                if(m[c.substr(0,i)].size()==4)
                    m[c.substr(0,i)].pop_back();
            }
        }
        for(int  i=1;i<=s.size();i++){
            res.push_back(m[s.substr(0,i)]);
        }
        return res;
    }
};