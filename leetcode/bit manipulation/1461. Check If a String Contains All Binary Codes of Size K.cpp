// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
class Solution {
public:
     bool hasAllCodes(string s, int k) {
        unordered_set<string> set;
        for(int i=0;i+k<=s.size();i++) set.insert(s.substr(i, k));
        return set.size()==pow(2, k);
    }
};