class Solution {
public:
    //time O(n) space O(n)
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res=0;
        for(int i=0;i<n;i++){
            res=max(res,dfs(manager,informTime,i));
        }
        return res;
    }
    int dfs(vector<int>& manager,vector<int>& informTime,int cur){
        if(manager[cur]!=-1){
            //once we reach a non head node
            //we find the sum of inform time thats above the current element
            //and go onto adding them
            informTime[cur]+=dfs(manager,informTime,manager[cur]);
            //since we have calulated when xyz was the manager we don't need to calculate it again
            manager[cur]=-1;
        }
        return informTime[cur];
    }
};