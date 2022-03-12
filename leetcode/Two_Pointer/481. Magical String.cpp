// https://leetcode.com/problems/magical-string/

class Solution {
public:
    int magicalString(int n) {
        string s = " 122";
        for (int i = 3; i <= n; ++i) 
            s.append(s[i] - '0', i & 1 ? '1' : '2');
        return count(s.begin(), s.begin() + n + 1, '1');
    }
};