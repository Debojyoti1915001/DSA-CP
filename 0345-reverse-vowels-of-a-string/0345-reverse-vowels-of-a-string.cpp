class Solution {
public:
    bool isVowel(char c){
        c=tolower(c);
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            while(i<j&&!isVowel(s[i]))i++;
            while(i<j&&!isVowel(s[j]))j--;
            swap(s[i],s[j]);
            i++,j--;
        }
        return s;
    }
};