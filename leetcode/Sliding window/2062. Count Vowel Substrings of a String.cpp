Solution 1. Brute Force
// OJ: https://leetcode.com/problems/count-vowel-substrings-of-a-string/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
public:
    int countVowelSubstrings(string s) {
        int ans = 0, N = s.size();
        unordered_map<char, int> cnt;
        for (int i = 0; i < N; ++i) {
            cnt.clear();
            for (int j = i; j < N && isVowel(s[j]); ++j) {
                cnt[s[j]]++;
                if (cnt.size() == 5) ++ans;
            }
        }
        return ans;
    }
};
Solution 2. Sliding Window
Check out "C++ Maximum Sliding Window Cheatsheet Template!"

Function atMost(s, goal) returns the number of substrings that has at most goal number of unique vowels. The answer is atMost(s, 5) - atMost(s, 4).

// OJ: https://leetcode.com/problems/count-vowel-substrings-of-a-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
    int atMost(string &s, int goal) {
        int ans = 0, i = 0, j = 0, N = s.size();
        unordered_map<char, int> cnt;
        for (; j < N; ++j) {
            if (!isVowel(s[j])) {
                i = j + 1;
                cnt.clear();
                continue;
            }
            cnt[s[j]]++;
            for (; cnt.size() > goal; ++i) {
                if (--cnt[s[i]] == 0) cnt.erase(s[i]);
            }
            ans += j - i + 1; // this window [i, j] is the maximum window ending at `s[j]` that has at most `goal` number of unique vowels.
        }
        return ans;
    }
public:
    int countVowelSubstrings(string s) {
        return atMost(s, 5) - atMost(s, 4);
    }
};
🌟 Sliding Window "At Most to Equal" trick
NOTE: this is an extension to my "C++ Maximum Sliding Window Cheatsheet Template!". Please make sure you are familiar with this template first.

For problems solvable using this trick, also check out "C++ Maximum Sliding Window Cheatsheet Template!"

For a find maximum sliding window problem that is looking for windows with exactly k something in it, we can convert it to a problem that is looking for at most k something in it.

It's because "number of windows with exactly k something in it" = "number of windows with at most k something in it" - "number of windows with at most k - 1 something in it".

Take 930. Binary Subarrays With Sum (Medium) for example, if we want to use the "find maximum sliding window template" without this trick, we would need to use 3 pointers -- i as the left edge of the window with goal number of 1s in it, j as the left edge of the window with goal - 1 number of 1s in it, and k as the right edge.

// OJ: https://leetcode.com/problems/binary-subarrays-with-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int goal) {
        int i = 0, j = 0, k = 0, N = A.size(), sum1 = 0, sum2 = 0, ans = 0;
        for (; k < N; ++k) {
            sum1 += A[k];
            sum2 += A[k];
            while (i <= k && sum1 > goal) sum1 -= A[i++];
            while (j <= k && sum2 > goal - 1) sum2 -= A[j++];
            ans += j - i;
        }
        return ans;
    }
};
This code is repetitive -- we need to do similar jobs for i and j, and keep states for both windows.

By extracting an atMost function, we make the code cleaner and less error-prone.

// OJ: https://leetcode.com/problems/binary-subarrays-with-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int atMost(vector<int> &A, int goal) {
        int i = 0, j = 0, N = A.size(), sum = 0, ans = 0;
        for (; j < N; ++j) {
            sum += A[j];
            while (i <= j && sum > goal) sum -= A[i++];
            ans += j - i;
        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& A, int goal) {
        return atMost(A, goal) - atMost(A, goal - 1);
    }
};