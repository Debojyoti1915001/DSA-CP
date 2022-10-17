class Solution {
public:
    void func(int ind, int sum, int count, int n, vector<int> &nums, vector<vector<int>> &a){
        if(ind==n)
        {
            a[count].push_back(sum);
            return;
        }
        func(ind+1, sum, count, n, nums, a);
        func(ind+1, sum+nums[ind], count+1, n, nums, a);
    }
    
    int minimumDifference(vector<int>& nums) {
        vector<vector<int>> a(nums.size()/2+1), b(nums.size()/2+1);
        int total=0, mn=INT_MAX;
        for(auto num: nums)
            total+=num;
        func(0, 0, 0, nums.size()/2, nums, a);
        func(nums.size()/2, 0, 0, nums.size(), nums, b);
        
        for(int i=0; i<=nums.size()/2; i++)
            sort(a[i].begin(), a[i].end());

        for(int i=0; i<=nums.size()/2; i++)
            for(int j=0; j<b[i].size(); j++)
            {
                auto it=lower_bound(a[nums.size()/2-i].begin(), a[nums.size()/2-i].end(), 
                                    total/2-b[i][j]);
                if(it!=a[nums.size()/2-i].end())
                    mn=min(mn, abs(total - 2*(b[i][j]+*it)));
                it--;
                if(it>=a[nums.size()/2-i].begin())
                    mn=min(mn, abs(total - 2*(b[i][j]+*it)));
            }
        return mn;
    }
};