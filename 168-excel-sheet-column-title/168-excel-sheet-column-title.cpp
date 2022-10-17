class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n){
            n-=1;
            char c=('A'+n%26);
            ans= c + ans;
            n=n/26;
        }
        return ans;
    }
};