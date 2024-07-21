class Solution {
public:
    int maxOperations(string s) {
        int one=0,ans=0;
        s.push_back('1');
        for(int i=0;i<s.size();i++){
            if(i>0&&s[i-1]=='0'&&s[i]=='1'){
                ans+=one;
            }
            if(s[i]=='1'){
                one++;
            }
        }
        return ans;
    }
};