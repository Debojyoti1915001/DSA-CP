class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res=0;
        for(int i=0;i<n;i++){
            res=max(res,dfs(manager,informTime,i));
        }
        return res;
    }
    int dfs(vector<int>& manager, vector<int>& informTime,int cur){
        if(manager[cur]!=-1){
            informTime[cur]+=dfs(manager,informTime,manager[cur]);
            manager[cur]=-1;
        }
        return informTime[cur];
    }
};