class Solution {
public:
    string gcdOfStrings(string a, string b) {
        if(a.length()<b.length())return gcdOfStrings(b,a);
        if(b.size()==0)return a;
        if(a.substr(0,b.size())!=b)return "";
        return gcdOfStrings(a.substr(b.size() ),b);
    }
};