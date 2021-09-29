// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/

class Solution {
public:
   int findKthNumber(int m, int n, int k) {
		int lo = 1, hi = m*n;
		while (lo < hi) {
			int mid = lo + (hi-lo)/2;
			if (countNums(m, n, mid) >= k)
				hi = mid;
			else lo = mid+1;
		}
		return lo;
	}
	
	int countNums(int R, int C, int num) {
		int count = 0;
		for (int row=1; row <= R; row++) {
			int add = min(C, num/row);
			if (add == 0) break;
			count += add;
		}
		return count;
	}
};