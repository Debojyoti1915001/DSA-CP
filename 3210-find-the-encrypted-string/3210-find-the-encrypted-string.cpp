class Solution {
public:
    string getEncryptedString(string s, int k) {
        k=k%s.size();
        return s.substr(k,s.size())+s.substr(0,k);
    }
};