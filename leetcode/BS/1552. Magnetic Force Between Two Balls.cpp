// https://leetcode.com/problems/magnetic-force-between-two-balls/

class Solution {
public:
    int maxDistance(vector<int>& p, int toPlace) {
		sort(p.begin(), p.end());
		int lo = 1, hi = (p.back()-p.front()) / (toPlace-1), ans = 1;

		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			if (isPossible(p, toPlace, mid))
				ans = mid, lo = mid + 1;
			else
				hi = mid - 1;
		}

		return ans;
	}
    bool isPossible(vector<int>&p,int toPlace,int dist){
        int placed=1;
        int i=0;
        for(int j=1;j<p.size();j++){
            if(p[j]-p[i]>=dist){
                placed++;
                i=j;
            }
        }
        return placed>=toPlace;
    }
};