class Solution {
public:
    int minFlips(string target) {
        int state=0,cnt=0;
        for(auto c:target){
            if(c-'0'!=state){
                state=c-'0';
                cnt++;
            }
        }
        return cnt;
    }
};