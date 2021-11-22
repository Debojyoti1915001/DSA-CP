// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    static bool comp(vector<int>a,vector<int>b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>>ans;
        if(intervals.size()==0)return ans;
        ans.push_back({intervals[0][0],intervals[0][1]});
        for(int i=1;i<intervals.size();i++){
            if(ans.back()[1]<intervals[i][0]){
                ans.push_back({intervals[i][0],intervals[i][1]});
            }else{
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};