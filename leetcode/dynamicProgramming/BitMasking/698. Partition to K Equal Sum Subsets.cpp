class Solution {
public:
    int n;
    unordered_map<int,bool>m;
    bool solve(vector<int>& nums,int vis,int cur, int req,int idx,int k){
        //since we divide initially if k==1 this will surely be satisfied
        if(m.count(vis))return m[vis];//so that we don't repeat the sequence we calculated earlier
        if(k==1)return true;
        if(cur==req)return m[vis]=solve(nums,vis,0,req,0,k-1);
        //check for each index
        for(int i=idx;i<n;i++){
            if(((vis>>i)&1)==0&&cur+nums[i]<=req){
                vis=vis|(1<<i);//set the ith bit
            if(solve(nums,vis,cur+nums[i],req,i,k))return m[vis]=true;
            vis=vis^(1<<i);//reset the ith bit
            }
        }
        return m[vis]=false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n=nums.size();
        int sum=0;
        for(auto &i:nums){
            sum+=i;
        }
        int vis=0;
        if(sum%k!=0)return false;
        return solve(nums,vis,0,sum/k,0,k);
    }
};