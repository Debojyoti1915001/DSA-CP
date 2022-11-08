class Solution {
public:
    string makeGood(string s) {
        string ans;
        for(auto c:s){
            if(ans.size()!=0&&islower(ans.back())&&isupper(c)&&ans.back()==tolower(c)){
                ans.pop_back();
            }else if(ans.size()!=0&&islower(c)&&isupper(ans.back())&&c==tolower(ans.back())){
                ans.pop_back();
            }else ans+=c;
        }
        return ans;
    }
};