// https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {

	using vv = pair<int, vector<int>>;
	priority_queue<vv, vector<vv>, greater<vv>> q;
	vector<int> vec;

	set<vector<int>> visited;

	vector<int> num(mat.size(), 0);
	int sumVal = 0;
	for (int i = 0; i < num.size(); ++i) sumVal += mat[i][num[i]];
	visited.insert(num);
	q.push({sumVal, num});

	while (vec.size() < k) {

		if (q.empty()) return -1;

		vector<int> curr = q.top().second;
		vec.push_back(q.top().first);
		q.pop();

		for (int i = 0; i < curr.size(); ++i) {
			if (curr[i] + 1 < mat[0].size()) {
				++curr[i];
				if (visited.find(curr) == visited.end()) {
					int val = vec.back() + mat[i][curr[i]] - mat[i][curr[i] - 1];
					q.push({val, curr});
					visited.insert(curr);
				}
				--curr[i];
			}
		}
	}

	return vec.back();
}
};