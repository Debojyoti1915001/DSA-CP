class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        int ans=0,sz=v.size();
        for(int i=0;i<v.size();i++){
            int start=v[i][0],end=v[i][1];
            int j=i+1;
            int checkStart = (j < sz) ? (v[j][0]) : sz;
            int checkEnd = (j < sz) ? (v[j][1]) : sz;
            while (j < sz && start <= checkStart && checkStart <= end) {
                start = max(start, checkStart);
                end = min(end, checkEnd);
                j++;
                checkStart = (j < sz) ? (v[j][0]) : sz;
                checkEnd = (j < sz) ? (v[j][1]) : sz;
            }
            i = j;
            i--;
            ans++;
        }
        return ans;
    }
};