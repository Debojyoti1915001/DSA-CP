// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

class Solution {
public:
	/*
	* We have to maximize the bits from left to right. Basically try to make the left ones '1'
	* Let's say we have maximized till i-1th bit (31, 30, ... i-1, i, ....0) and say we have got
	* a ans = m till now (11011..ith...000000). We can now only check the pairs, which on XOR
	* gives us the same as m till i-1th bit. We want the ith bit to be 1, greedy m = 11011...1..000
	* It might or might not be possible to get. Let's check:
	* Add all the nos in a set. Use the fact that if a^b=c ==> a^c=b. So num1^num2 = ans ==> num1^ans = num2
	* Think of it similar to (a+b=c) problem. Where you have to find pairs, given c.
	* Iterarate on nums and check if there is some number in our set such that it has same starting i bits as ans^numi = k,
	* How to do that? Rather than inserting nums in set, insert nums&(11111..till_i_th..00000) in the set. Done!!!!
	*/

	int n;
	int findMaximumXOR(vector<int>& nums) {
		n = nums.size();

		int ans = 0, mask = 0;
		for (int i = 31; i >= 0; --i) {
			mask = mask | (1 << i);
			int greedyAns = (ans | (1 << i));
			//Check if possible
			unordered_set<int> s;
			for (auto &num : nums) {
				//We basically insert with first i bits conserved and the rest of the bits are 0 after i
				s.insert(num & mask);
			}

			for (auto &prefix : s) {
				if (s.find(greedyAns ^ prefix) != s.end()) {
					ans = greedyAns;
					break;
				}
			}
		}

		return ans;
	}
};