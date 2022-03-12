class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       //sorting so that we have to check only on cond that is if nums[j] is divisible by nums[i]
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>parent(n);//link to parent of it
        vector<int>cnt(n);//for storing the count
        int m=0,//number of elements in that subset
        mi=0;//minimum index
        for(int i=n-1;i>=0;i--){
            //iterate from backwards
            //if we can divide the current element with rem zero
            //we will check if adding that element will be benificial
            for(int j=i;j<n;j++){
                //cnt[j]+1 means that we are adding the current element to the current list starting with i
                if(nums[j]%nums[i]==0&&cnt[j]+1>cnt[i]){
                    cnt[i]=cnt[j]+1;
                    parent[i]=j;//we are linking to the parent
                }
            }
            if(cnt[i]>m){
                m=cnt[i];
                mi=i;
            }
        }
        vector<int>res;
        for(int i=0;i<m;i++){
            res.push_back(nums[mi]);
            mi=parent[mi];
        }
    return res;
    }
    
};