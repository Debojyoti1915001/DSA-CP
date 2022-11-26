class Solution {
public:
//     Explanation
// Sort the jobs by endTime.

// dp[time] = profit means that within the first time duration,
// we cam make at most profit money.
// Intial dp[0] = 0, as we make profit = 0 at time = 0.

// For each job = [s, e, p], where s,e,p are its start time, end time and profit,
// Then the logic is similar to the knapsack problem.
// If we don't do this job, nothing will be changed.
// If we do this job, binary search in the dp to find the largest profit we can make before start time s.
// So we also know the maximum cuurent profit that we can make doing this job.

// Compare with last element in the dp,
// we make more money,
// it worth doing this job,
// then we add the pair of [e, cur] to the back of dp.
// Otherwise, we'd like not to do this job.


// Complexity
// Time O(NlogN) for sorting
// Time O(NlogN) for binary search for each job
// Space O(N)

    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int n=s.size();
        vector<vector<int>>jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({e[i],s[i],p[i]});
        }
        sort(jobs.begin(),jobs.end());
        map<int,int>dp={{0,0}};
        for(auto &job:jobs){
            int cur=prev(dp.upper_bound(job[1]))->second+job[2];
            if(cur>dp.rbegin()->second)
                dp[job[0]]=cur;
        }
        return dp.rbegin()->second;
    }
};