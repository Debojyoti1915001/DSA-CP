class Solution {
public:
    void dfs(vector<int>& arr, int target,vector<vector<int>>&res, vector<int>&temp,int idx){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(target<0)return;
        for(int i=idx;i<arr.size();i++){
            if(i>idx&&arr[i]==arr[i-1])continue;
            if(arr[i]>target)break;
            temp.push_back(arr[i]);
            dfs(arr,target-arr[i],res,temp,i+1);    
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>ds;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,res,ds,0);
        return res;
    }
};