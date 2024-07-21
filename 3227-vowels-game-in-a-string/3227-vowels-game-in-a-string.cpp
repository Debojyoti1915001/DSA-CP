class Solution {
public:
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
            return true;
        }
        return false;
    }
    bool doesAliceWin(string s) {
        for(auto &i:s){
            if(isVowel(i)){
                return true;
            }
        }
        return false;
    }
};