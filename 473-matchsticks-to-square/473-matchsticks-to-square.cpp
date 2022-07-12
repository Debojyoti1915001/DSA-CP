class Solution {
public:
    bool solve(vector<int> v,int tempSum,int sum,int cnt,int cur,vector<int>&vis){
        if(cnt==4)return true;
        if(tempSum>sum)return false;
        if(sum==tempSum)return solve(v,0,sum,cnt+1,0,vis);
        //i to start from cur since its sorted
        for(int i=cur;i<v.size();i++){
            if(vis[i])continue;
            //if i didn't take 2 and cur ele is 2 we will move on
            if(i>0&&v[i]==v[i-1]&&!vis[i-1])continue;
            vis[i]=1;
            if(solve(v,tempSum+v[i],sum,cnt,i+1,vis))return true;
            vis[i]=0;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        int n=matchsticks.size();
        sort(matchsticks.begin(),matchsticks.end());
        if(sum%4)return false;
        sum=sum/4;
        vector<int> vis(n);
        //if the largest ele is greater than req sum
        if(matchsticks[n-1]>sum)return false;
        
        return solve(matchsticks,0,sum,1,0,vis);               
    }
};