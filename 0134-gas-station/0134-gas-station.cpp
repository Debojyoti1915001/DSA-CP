class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int idx=0,n=cost.size();
        int total=0,cur=0;
        for(int i=0;i<n;i++){
            total+=gas[i]-cost[i];
            cur+=gas[i]-cost[i];
            //if in certain place the cur value is less than 0 we have to start from (i+1)th index
            if(cur<0){
                cur=0;
                idx=i+1;
            }
        }
        //if the total diff is less than 0 it is not possible 
        if(total<0)return -1;
        return idx;
    }
};